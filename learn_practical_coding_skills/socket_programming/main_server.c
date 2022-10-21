#include "socket.h"

int main(int argc, char *argv[]){
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";
	int str_len; 

	if(argc != 2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
		error_handling("bind() error");

	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr);

	while(1){
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	printf("client address : %s\n",inet_ntoa(clnt_addr.sin_addr)); // print ip
	
	if(clnt_sock == -1)
		error_handling("accept() error");
	else                       
		printf("Connected client\n");

	while((str_len = read(clnt_sock, message, BUF_SIZE)) != 0)
		write(clnt_sock, message, str_len);
	
	if(strcmp(message, "q"))
		break;
	printf("Message from client : %s\n", message);

	close(clnt_sock);
	}

	close(serv_sock);

	return 0;
}
