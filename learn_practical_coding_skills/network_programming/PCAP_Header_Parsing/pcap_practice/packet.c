/*
 *
 *	read pcap and print ip, port, protocol by format
 *
 * */

#include "packet.h"


void packet_handler(u_char *handle, const struct pcap_pkthdr* pkthdr, const u_char* packet){
	struct ether_header *ep;
	unsigned short ether_type;
	int length = pkthdr->len;
	
	ep = (struct ether_header*)packet;

	if(handle == NULL)
			length++;

	//get ip header
	packet += sizeof(struct ether_header);

	//get protocol type
	ether_type = ntohs(ep->ether_type);

	if(ether_type == ETHERTYPE_IP){
		iph = (struct ip*)packet;

		if(iph->ip_p == IPPROTO_TCP){		
			tcph = (struct tcphdr *)(packet + iph->ip_hl * 4);
			printf("%s:%d -> %s:%d [%s]\n", inet_ntoa(iph->ip_src), ntohs(tcph->source), inet_ntoa(iph->ip_dst), ntohs(tcph->dest), "TCP");
		}
	}

	//if(ether_type == ETHERTYPE_IP){
	//	iph = (struct ip*)packet;
	//	printf("Src Address : %s\n", inet_ntoa(iph->ip_src));
	//	printf("Dst Address : %s\n", inet_ntoa(iph->ip_dst));

	//	if(iph->ip_p == IPPROTO_TCP){
	//		tcph = (struct tcphdr *)(packet + iph->ip_hl * 4);
	//		printf("Src port : %d\n", ntohs(tcph->source));
	//		printf("Drc port : %d\n", ntohs(tcph->dest));
	//	}
	//}

}
