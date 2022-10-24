#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(void){
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	char *net;
	char *mask;
	int ret;
	bpf_u_int32 netp; // ip
	bpf_u_int32 maskp; // subnet mask
	struct in_addr addr;

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


	return 0;
}
