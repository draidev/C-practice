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
	
	char fname[32];


	optind = 1;
	while((option = getopt(argc, argv, optstring)) != -1){
		switch(option) {
			case 'w':
				while(1){
					printf("===== pcap_open_live =====\n");
					handle = pcap_open_live(dev, BUFSIZ, PROMISCUOUS, -1, error_buffer);					if(handle == NULL){
						printf("%s\n", error_buffer);
						exit(1);
					}

					// make file name
					timer = time(NULL);
					t = localtime(&timer);
					time_flag = t->tm_min;
					printf("time_flag : %d\n", time_flag);
					sprintf(fname, "%04d_%02d_%02d_%02d_%02d.pcap", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min);


					// pcap dump
					printf("===== pcap_dump_open =====\n");
					printf("version :: %s\n", pcap_lib_version());
					pcap_dumper_t *df;
					df = pcap_dump_open(handle, fname);
					if(df == 0) {printf("fail dump_open\n"); return 3;}

					if(pcap_loop(handle, 0, packet_handler_live, (u_char*)df) < 0){
						printf("pcap_loop() failed: %s\n", pcap_geterr(handle));
						return 2;
					}
					else
						printf("Real-Time pcap capture loop success!\n");
					
					printf("after pcap_loop\n");

					memset(fname, 0, 32*sizeof(char)); //initialize a file name for a new file
					// attach pcap_header and close
					file_write_pcap_file_header(df);
					pcap_dump_close(df);
					pcap_close(handle);
				}
				break;
				
			case 'r':
				handle = pcap_open_offline(argv[2], error_buffer);					
				if(pcap_loop(handle, 0, packet_handler_offline, NULL) < 0) {
					printf("pcap_loop() failed: %s", pcap_geterr(handle));
					return 2;
				}
				else
					printf("loop success!\n");
					
				pcap_close(handle);

				break;
		}
	}

	return 0;
}
