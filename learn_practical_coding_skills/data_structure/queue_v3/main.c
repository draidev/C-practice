/*
use double pointer at queue datatype
*/

#include "thread.h"

int main(void)
{
 	QUEUE Q;
	char *input;
  	pthread_t *pthread;
	int i;

	pthread = (pthread_t*)malloc(sizeof(pthread));
	pthread_create(pthread, NULL, thread_routine, &Q);

	Q.head = 0;
	Q.tail = 0;

	input = (char*)malloc(sizeof(char)*STRLEN);
	Q.arr = (char**)malloc(sizeof(char*)*MAX);
	for(i = 0; i < MAX; i++)
	{
		*(Q.arr+i) = (char*)malloc(sizeof(char)*STRLEN);
	}

	while(scanf("%s",input)==1)
	{
		enqueue(&Q, input);
		if(strcmp(input,"q")==0)
			break;
		
		memset(input, 0, STRLEN);
	}
	//printf("end while\n");

	pthread_join(*pthread, NULL);
		
	free(pthread);
	free(input);
	for(i = 0; i < MAX; i++)
	{
		free(*(Q.arr+i));
	}
	free(Q.arr);

	return 0;
}
