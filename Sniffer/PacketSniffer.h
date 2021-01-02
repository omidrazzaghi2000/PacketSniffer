#ifndef C_PACKET_SNIFFER_MAIN_H
#define C_PACKET_SNIFFER_MAIN_H


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <QSqlDatabase>
#include <QDebug>
#include <netinet/ether.h>
#include <PacketSniffer.h>
#include <iostream>
#include <string.h>



#define ETH_ADDRESS_LENGTH 6
#define ETH_HEADER_LENGTH 14






struct ethernet_frame {
    unsigned char source_mac_addr[ETH_ADDRESS_LENGTH];//1byte
    unsigned char dest_mac_addr[ETH_ADDRESS_LENGTH];//1byte
    unsigned short protocol;//2bytes
};


struct ipv4_header {
    unsigned char ihl : 4;
    unsigned char version : 4;
    unsigned char type_of_service;
    unsigned short total_length;
    unsigned short identification;
    unsigned short flags_and_fragment_offset;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short header_checksum;
    unsigned int src_ip_addr;
    unsigned int dst_ip_addr;
};

class ipv4{
public:
    unsigned char version;
    unsigned short total_length;
    unsigned short flags_and_fragment_offset;
    unsigned char ttl;
    unsigned char protocol;
    QString src_ip_addr;
    QString dst_ip_addr;
    int packet_number;
    QSqlDatabase * db;
    void save();
    ipv4(int pn,QSqlDatabase * _db){
        packet_number = pn;
        db = _db;
    }
};


struct tcp_header {
    unsigned short src_port;
    unsigned short dest_port;
    u_int32_t sequence;
    u_int32_t acknowledgment;
    unsigned char reserved :4;
    unsigned char data_offset :4;
    unsigned char flags;
    unsigned short window_size;
    unsigned short checksum;
    unsigned short urgent_pointer;
};

class tcp{
public:
    int packet_number;
    QSqlDatabase * db;
    unsigned short src_port;
    unsigned short dest_port;
    u_int32_t sequence;
    u_int32_t acknowledgment;
    unsigned char data_offset :4;
    void save();
    tcp(int pn,QSqlDatabase * _db){
        packet_number = pn;
        db = _db;
    }

};

struct udp_header {
    unsigned int src_port : 16;
    unsigned int dst_port : 16;
    unsigned int length : 16;
    unsigned int checksum : 16;
};


class udp{
public:
    int packet_number;
    QSqlDatabase * db;
    unsigned int src_port : 16;
    unsigned int dst_port : 16;
    unsigned int length : 16;
    void save();
    udp(int pn,QSqlDatabase * _db){
        packet_number = pn;
        db = _db;
    }

};

struct icmp_packet {
    unsigned int type : 8;
    unsigned int code : 8;
    unsigned int checksum : 16;
    unsigned char rest_of_header;
};

class icmp{
public:
    int packet_number;
    QSqlDatabase * db;
    unsigned int type : 8;
    unsigned int code : 8;
    void save();
    icmp(int pn,QSqlDatabase * _db){
        packet_number = pn;
        db = _db;
    }

};

class EthernetFrame{
public:

    int packet_number;
    QString source_mac_address;
    QString destination_mac_address;
    int eth_proto;
    QSqlDatabase *db;
    void save();
    EthernetFrame(int pn,QSqlDatabase* _db){
        packet_number = pn;
        db = _db;
    }

};





/**
 * Recursively checks the extension headers
 */
int do_extension_headers (int, const u_char *);


/**
 * Prints out the data in raw and ascii format.
 * The raw and ascii correspond with each other, being
 * raw on the lhs, and ascii on the right
 *
 * This method was taken from Github - can't remember who I got it from
 */
void dump (const unsigned char *, unsigned int);




/**
 * Converts a string to a MAC
 * in the format of xx:xx...
 */
QString mac_toupper (char *);


/**
 * Unpacks the ethernet frame, prints out the source and destination
 * MAC addresses and returns the protocol
 *
 * @param packet - the parsed data from tcpdump/pcap_file
 * @param EthernetFrame - ethernet frame packet
 * @return - the ethernet protocol - IPv4, IPv6, etc...
 */
int unpack_ethernet_header_frame (const u_char *,EthernetFrame&);


/**
 * Unpacks the IPv4 Packet, prints out the ipv4 header info
 *
 * @param packet - the parsed data from tcpdump + ETHERNET_HEADER_LENGTH
 * @param return - the IPv4 protocol - TCP/UDP/ICMP etc...
 */
int unpack_ipv4_packet (const u_char *);



/**
 * Prints the IPv4 address in the form of 127.0.0.1
 *
 * @param address - the bytes to be converted
 */
QString get_ipv4_address (char *, __uint32_t);


/**
 * Unpack the tcp segment and print valid information to std.err
 */
void tcp_segment (const u_char *);

/**
 * Unpacks the udp segment and print valid information to std.err
 */
void udp_segment (const u_char *);

/**
 * Unpacks the icmp packet and print valid informaiton to std.err
 */
void icmp_packet (const u_char *);

/**
 * Figures out whether it will be displaying IPv4 or IPv6 protocol.
 * This is done as tcp/udp will use the same functions regardless of
 * ip protocol.
 */
void do_protocol (int, const u_char *, int, unsigned int);

/**
 * The main function for parsing a packet
 */
void got_packet (u_char *, const struct pcap_pkthdr *, const u_char *);

/**
 * Start of program
 */
int startSniffing(int, char ** , QSqlDatabase * db);

/**
  *Stop sniffing
  *
  */
void stopSniffing();

/**
  * Connect to Database
  */
void save(EthernetFrame);













#endif
