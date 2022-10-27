/*

   read pcap file & print ip, port, protocol with format

*/

#include "packet.h"
#include "pcap_header.h"

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
	
	time_t timer;
	struct tm* t;
	char fname[32];
	int time_flag;


	optind = 1;
	while((option = getopt(argc, argv, optstring)) != -1){
		switch(option) {
			case 'w':
				handle = pcap_open_live(dev, BUFSIZ, PROMISCUOUS, -1, error_buffer);					if(handle == NULL){
					printf("%s\n", error_buffer);
					exit(1);
				}
			
				// make file name
				timer = time(NULL);
				t = localtime(&timer);
				sprintf(fname, "%04d_%02d_%02d_%02d_%02d.cap", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min);

				time_flag = t->tm_min;
				printf("time_flag : %d\n", time_flag);

				pcap_dumper_t *df;
				df = pcap_dump_open(handle, fname);
				if(df == 0) {printf("fail dump_open\n"); return 3;}

				if(pcap_loop(handle, 0, packet_handler_live, (u_char*)df) < 0){
					printf("pcap_loop() failed: %s", pcap_geterr(handle));
					return 2;
				}
				else
					printf("Real-Time pcap capture loop success!\n");
				
				file_write_pcap_file_header(df);

				break;
				
			case 'r':
				handle = pcap_open_offline(argv[2], error_buffer);					
				if(pcap_loop(handle, 0, packet_handler_offline, NULL) < 0) {
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




