#include "thread.h"

int main(void)
{
 	QUEUE Q;
	int input;
  	pthread_t *pthread;
	//char p1[] = "thread_1";
	//int i;

	pthread = (pthread_t*)malloc(sizeof(pthread));
	pthread_create(pthread, NULL, thread_routine, &Q);

	Q.head = 0;
	Q.tail = 0;

	printf("input num : ");
	scanf("%d", &input);
	
	enqueue(&Q, input);

	while(scanf("%d", &input)==1)
	{
		enqueue(&Q, input);
	}
	
	pthread_join(*pthread, NULL);
		
	free(pthread);
	return 0;
}
