#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void handler(int sig);
void handler(int sig){
    printf("signal no(%d) Received\n",sig);
}

int main(void){
while(1)
{
	if(signal(SIGUSR1, handler)==SIG_ERR){
	 	fprintf(stderr, "cannot set USR1\n");
		exit(1);
	}
}
		

}
