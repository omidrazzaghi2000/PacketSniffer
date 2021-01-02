#include <PacketSniffer.h>
#include <QSqlDatabase>
#include <iostream>
#include <string.h>
#include <utility>
#include <QSqlQuery>
#include <QHash>
#include <QVariant>
#include <stdio.h>
#include <QString>
int packet_number = 1;

pcap_t *handle;
QSqlDatabase * DB;

QString mac_toupper (char *mac)
{
    QString o;
    int i=0;
    while (mac[i])
    {
        putchar (toupper(mac[i]));
        o.append((const char*)(mac[i]));
        i++;
    }
    printf("\n");
    return o;
}

int unpack_ethernet_header_frame (const u_char *packet,EthernetFrame & ef) {

    struct ethernet_frame *eth_frame = (struct ethernet_frame *) packet;


    ef.source_mac_address = QString(ether_ntoa((struct ether_addr *) eth_frame->source_mac_addr));


    ef.destination_mac_address=QString(ether_ntoa((struct ether_addr *) eth_frame->dest_mac_addr));
    return eth_frame->protocol;
}


int unpack_ipv4_packet (const u_char *packet) {


    struct ipv4_header *ip_packet = (struct ipv4_header *) packet;
    ipv4 * record = new ipv4(packet_number,DB);
    record -> version = ip_packet->version;
    record -> total_length = ip_packet -> total_length;
    record -> flags_and_fragment_offset = ip_packet -> flags_and_fragment_offset;
    record -> ttl = ip_packet -> ttl;
    record -> protocol = ip_packet->protocol;
//    printf("\tVersion: %d\n", ip_packet->version);
//    printf("\tTotal Length: %d\n", ip_packet->total_length);
//    printf("\tTime To Live: %d\n", ip_packet->ttl);
    record -> src_ip_addr = get_ipv4_address("\tSource Address", ip_packet->src_ip_addr);
    record -> dst_ip_addr = get_ipv4_address("\tDestination Address", ip_packet->dst_ip_addr);
    record -> save();
    return ip_packet->protocol;
}

void dump (const unsigned char *data_buffer, const unsigned int length) {

    // printf("\t\tPayload: (%d bytes)\n\n", length - 32);
    // unsigned char byte;
    // unsigned int i, j;

    // for (i = 0; i < length; i++) {
    //     byte = data_buffer[i];
    //     printf("%02x", data_buffer[i]);
    //     if (((i % 16) == 15) || (i == length - 1)) {
    //         for (j = 0; j < 15 - (i % 16); j++)
    //             printf("  ");
    //         printf("| ");
    //         for (j = (i - (i % 16)); j <= i; j++) {
    //             byte = data_buffer[j];
    //             if ((byte > 31) && (byte < 127))
    //                 printf("%c", byte);
    //             else
    //                 printf(".");
    //         }
    //         printf("\n");
    //     }
    // }
}

QString get_ipv4_address (char *msg, __uint32_t address ) {
    struct in_addr ip;

    ip.s_addr = address;
    char * buffer=inet_ntoa(ip);


    return QString(buffer);
//    printf("%s: %s\n", msg, inet_ntoa(ip));
}

void tcp_segment (const u_char *packet) {
    struct tcp_header *tcp_segment = (struct tcp_header *) packet;
    tcp * record = new tcp(packet_number,DB);
    record->src_port= ntohs(tcp_segment->src_port);
    record->dest_port = ntohs(tcp_segment->dest_port);
    record->sequence= ntohl(tcp_segment->sequence);
    record->acknowledgment = ntohl(tcp_segment->acknowledgment);
    record->acknowledgment = tcp_segment->data_offset;
    record->save();
//    printf("\t\tSource Port: %d\n", ntohs(tcp_segment->src_port));
//    printf("\t\tDestination Port: %d\n", ntohs(tcp_segment->dest_port));
//    printf("\t\tSequence: %d\n", ntohl(tcp_segment->sequence));
//    printf("\t\tAcknowledgement: %d\n", ntohl(tcp_segment->acknowledgment));
//    printf("\t\tData Offset: %d\n", tcp_segment->data_offset);
}

void udp_segment (const u_char *packet)
{
    struct udp_header *udp_segment = (struct udp_header *) packet;
    udp * record = new udp(packet_number,DB);
    record->src_port= ntohs(udp_segment->src_port);
    record->dst_port= ntohs(udp_segment->dst_port);
    record->length  = ntohs(udp_segment->length);
    record->save();
//    printf("\t\tSource Port: %d\n", ntohs(udp_segment->src_port));
//    printf("\t\tDestination Port: %d\n", ntohs(udp_segment->dst_port));
//    printf("\t\tLength: %d\n", ntohs(udp_segment->length));
}

void icmp_packet (const u_char *packet)
{
    struct icmp_packet *icmp_header = (struct icmp_packet *) packet;
    icmp * record = new icmp(packet_number,DB);
    record->type = icmp_header->type;
    record->code = icmp_header->code;
    record->save();
//    printf("\t\tType: %d\n", icmp_header->type);
//    printf("\t\tCode: %d\n", icmp_header->code);

}

void do_protocol (int ip_proto, const u_char *packet, int ipv, unsigned int header_len)
{

    int ip_header_size = sizeof(struct ipv4_header);        //version 4 by default

    packet = packet + ip_header_size;


        // TCP
    if (ip_proto == 6)
    {
//        printf("\tTCP Segment:\n");
        tcp_segment(packet);

        // print data
//        dump((packet + sizeof(struct tcp_header)), header_len);

    }

        // UDP
    else if (ip_proto == 17)
    {
//        printf("\tUDP Segment:\n");
        udp_segment(packet);

        // print data
        // dump((packet + sizeof(struct udp_header)), header_len);

    }

        // ICMPv4
    else if (ip_proto == 1)
    {
//        printf("\tICMPv4 Packet:\n");
        icmp_packet(packet);

        // print data
        // dump((packet + sizeof(struct icmp_packet)), header_len);
    }

    else
    {
//       printf("Unknown\n");
    }
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    // now we have the packet, we need to break it open
    // we start with the ethernet_frame
//    printf("\nEthernet Frame: #%d\n", packet_number++);

    EthernetFrame * ef = new EthernetFrame(packet_number,DB);

    int ip_proto; 
    int eth_proto = unpack_ethernet_header_frame(packet,*ef);
    ef->eth_proto = eth_proto;
    switch (eth_proto) {

        case 8:                                     // IPv4
//            printf("Protocol: IPv4\n");

            // unpack the IPv4 packet
            ip_proto = unpack_ipv4_packet(packet + ETH_HEADER_LENGTH);

            do_protocol(ip_proto, packet + ETH_HEADER_LENGTH, 4, header->len);

            break;

        default:
//            printf("Protocol: Unknown\n");
            break;
    }

//    printf("\n");
    ef->save();
    packet_number++;
}

int startSniffing(int argc, char **argv ,QSqlDatabase * _db )
{

    DB=_db;
    packet_number = 1;
    char errbuff[PCAP_ERRBUF_SIZE];

    handle = pcap_fopen_offline(popen("tcpdump -s0 -w -","r"), errbuff);
    if (NULL == handle)
    {
        printf("Error: %s\n", errbuff);
        return 1;
    }


    pcap_loop(handle, 1024*1024, got_packet, NULL);

    pcap_close(handle);
    qDebug() << "Finish";
    return 0;
}

void stopSniffing(){
    qDebug()<<"[Packet Snniffing] Stopped.";
    if(handle!=NULL)
    pcap_breakloop(handle);
}

void EthernetFrame::save(){


    if(db->open()){
        QSqlQuery query;
        query.prepare("INSERT INTO ethernet_packets (packet_number,source_mac_addr,dest_mac_address,protocol)"
                      "VALUES (:pn,:smd,:dma,:p)");

        query.bindValue(":pn",packet_number);
        query.bindValue(":smd",source_mac_address);
        query.bindValue(":dma",destination_mac_address);
        query.bindValue(":p",eth_proto);
        query.exec();
    }

}

void ipv4::save(){

    if(db->open()){
        QSqlQuery query;
        query.prepare("INSERT INTO ipv4 (packet_number,version,length,ttl,fragment,src_ip,des_ip,protocol)"
                      "VALUES (:pn,:v,:l,:t,:f,:s,:d,:p)");

        query.bindValue(":pn",packet_number);
        query.bindValue(":v",version);
        query.bindValue(":l",total_length);
        query.bindValue(":t",ttl);
        query.bindValue(":f",flags_and_fragment_offset);
        query.bindValue(":s",src_ip_addr);
        query.bindValue(":d",dst_ip_addr);
        query.bindValue(":p",protocol);
        query.exec();
    }
}

void tcp::save(){
    if(db->open()){
        QSqlQuery query;
        query.prepare("INSERT INTO tcp_segment (packet_number,src_port,dest_port,sequence,ack,data_offset)"
                      "VALUES (:pn,:s,:d,:seq,:ack,:do)");

        query.bindValue(":pn",packet_number);
        query.bindValue(":s",src_port);
        query.bindValue(":d",dest_port);
        query.bindValue(":seq",sequence);
        query.bindValue(":ack",acknowledgment);
        query.bindValue(":do",data_offset);

        query.exec();
    }
}


void udp::save(){
    if(db->open()){
        QSqlQuery query;
        query.prepare("INSERT INTO udp_segment (packet_number,src_port,dest_port,length)"
                      "VALUES (:pn,:s,:d,:len)");

        query.bindValue(":pn",packet_number);
        query.bindValue(":s",src_port);
        query.bindValue(":d",dst_port);
        query.bindValue(":len",length);


        query.exec();
    }
}

void icmp::save(){
    if(db->open()){
        if(db->open()){
            QSqlQuery query;
            query.prepare("INSERT INTO icmp_packet (packet_number,type,code)"
                          "VALUES (:pn,:t,:c)");
            query.bindValue(":pn",packet_number);
            query.bindValue(":t",type);
            query.bindValue(":c",code);
            query.exec();
        }
    }
}


