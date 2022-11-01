/*

   read pcap file & print ip, port, protocol with format

*/

#include "packet.h"

int main(int argc, char* argv[]){
	char errbuf[PCAP_ERRBUF_SIZE];
	char *net;
	char *mask;
	pcap_if_t *alldevsp, *d;
	int ret, i = 1;
	bpf_u_int32 netp; // ip
	bpf_u_int32 maskp; // subnet mask
	struct in_addr addr;
	char error_buffer[PCAP_ERRBUF_SIZE];

	ret = pcap_findalldevs(&alldevsp, errbuf);

	if(ret == -1){
		printf("pcap_findalldev ERR : %s\n", errbuf);
		return -1;
	}

	for(d=alldevsp; d; d=d->next){
		printf("%d. %s", i++, d->name);
		if(d->description){
			printf("(%s)\n", d->description);
		}
		else
			printf("(None)\n");
	
	}
	//printf("device name : %s\n", dev);

	// get network mask&ip about network-device
	d = alldevsp;
	ret = pcap_lookupnet(d->name, &netp, &maskp, errbuf);

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

	pcap_freealldevs(d);
// =================================================================
// 2. read pcap and parsing
	const char *optstring = "r:w:";
	char option;

	pcap_t *handle;
	
	char fname[32];

	printf("version :: %s\n", pcap_lib_version());

	optind = 1;
	while((option = getopt(argc, argv, optstring)) != -1){
		switch(option) {
			case 'w':
				while(1){
					ret = pcap_findalldevs(&alldevsp, errbuf);
					
					printf("===== pcap_open_live =====\n");
					handle = pcap_open_live(alldevsp->name, BUFSIZ, PROMISCUOUS, -1, error_buffer);		
					if(handle == NULL){
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
					pcap_dumper_t *df;
					df = pcap_dump_open(handle, fname);
					if(df == 0) {printf("fail dump_open\n"); return 3;}

					if(pcap_loop(handle, 0, packet_handler_live, (u_char*)df) == -2){
						printf("pcap_breakloop \n");
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
					pcap_freealldevs(alldevsp);
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
