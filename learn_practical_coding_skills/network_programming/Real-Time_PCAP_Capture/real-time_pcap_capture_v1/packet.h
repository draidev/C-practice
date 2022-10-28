#ifndef PACKET_H
#define PACKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap/pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#include "pcap_header.h"

#define PROMISCUOUS 1
#define NONPROMISCUOUS 0

struct ip *iph;
struct tcphdr *tcph;

struct tm* t;
time_t timer;
int time_flag;

void packet_handler_offline(u_char *handle, const struct pcap_pkthdr* pkthdr, const u_char* packet);
void packet_handler_live(u_char *handle, const struct pcap_pkthdr* pkyhdr, const u_char* packet);

#endif
