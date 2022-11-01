/*
 *
 *	read pcap and print ip, port, protocol by format
 *
 * */

#include "packet.h"

void packet_handler_offline(u_char *handle, const struct pcap_pkthdr* pkthdr, const u_char* packet){
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
}


void packet_handler_live(u_char *handle, const struct pcap_pkthdr* pkthdr, const u_char* packet){
	int time_check;
	char fname[32];	

	timer = time(NULL);
	t = localtime(&timer);
	time_check = t->tm_min;

	printf("time_flag : %d  time_check : %d\n", time_flag, time_check);
	sprintf(fname, "%04d_%02d_%02d_%02d_%02d.pcap", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min);

	printf("===== pcap_dump_open =====\n");
	pcap_dumper_t *df;
	df = pcap_dump_open((pcap_t*)handle, fname);
	if(df == 0) printf("fail dump_open\n");

	if(time_flag == time_check)
		pcap_dump(handle, pkthdr, (u_char*)df);
	else{
		printf("\n\033[0;31m minute changed, make new file\033[0m\n\n");
		printf("time_flag : %d  time_check : %d\n", time_flag, time_check);
			
		memset(fname, 0, 32*sizeof(char)); //initialize a file name for a new file
		file_write_pcap_file_header(df);
		pcap_dump_close(df);
	}
}
