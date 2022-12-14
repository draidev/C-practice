#include "thread.h"

int main(void)
{
 	QUEUE Q;
	char input[STRLEN];
  	pthread_t *pthread;

	pthread = (pthread_t*)malloc(sizeof(pthread));
	pthread_create(pthread, NULL, thread_routine, &Q);

	Q.head = 0;
	Q.tail = 0;

	while(scanf("%s",input)==1)
	{
		enqueue(&Q, input);
	}

	pthread_join(*pthread, NULL);
		
	free(pthread);

	return 0;
}
