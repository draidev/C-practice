/*

   read pcap file & print ip, port, protocol with format

*/

#include "packet.h"

int main(int argc, char* argv[]){
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	char *net;
	char *mask;
	int ret;
	bpf_u_int32 netp; // ip
	bpf_u_int32 maskp; // subnet mask
	struct in_addr addr;
	char error_buffer[PCAP_ERRBUF_SIZE];

	dev = pcap_lookupdev(errbuf);

	if(dev == NULL){
		printf("cant find device by auto\n");
	}
	printf("device name : %s\n", dev);

	// get network mask&ip about network-device
	ret = pcap_lookupnet(dev, &netp, &maskp, errbuf);

	if(ret == -1){
		printf("%s\n", errbuf);
		exit(1);
	}

	addr.s_addr = netp;
	net = inet_ntoa(addr);

	if(net == NULL){
		perror("inet_ntoa");
		exit(1);
	}

	printf("net : %s\n", net);

	addr.s_addr = maskp;
	mask = inet_ntoa(addr);

	if(mask == NULL){
		perror("inet_ntoa");
		exit(1);
	}

	printf("mask : %s\n", mask);

// =================================================================
// 2. read pcap and parsing
	const char *optstring = "r:w:";
	char option;
	

	pcap_t *handle;
	//struct pcap_phkhdr *header;
	//const u_char *packet;
	//const struct ip *ip;

	optind = 1;
	while((option = getopt(argc, argv, optstring)) != -1){
		switch(option) {
			case 'w':
				
			case 'r':
				handle = pcap_open_offline(argv[2], error_buffer);					
				if(pcap_loop(handle, 0, packet_handler, NULL) < 0) {
					printf("pcap_loop() failed: %s", pcap_geterr(handle));
					return 2;
				}
				else
					printf("loop success!\n");
					
				break;
		}
	}

	pcap_close(handle);

	return 0;
}




