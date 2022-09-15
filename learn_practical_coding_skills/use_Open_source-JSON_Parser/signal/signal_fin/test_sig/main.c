#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void handler(int sig){
    printf("signal no(%d) Received\n",sig);
}

int main(void)
{  
    if(signal(SIGUSR1,handler)==SIG_ERR)    {
        fprintf(stderr,"cannot set USR1\n");
        exit(1);
    }                
    if(signal(SIGUSR2,handler)==SIG_ERR)  {
        fprintf(stderr,"cannot set USR2\n");
        exit(1);
    }

}
