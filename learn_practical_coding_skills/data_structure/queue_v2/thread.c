#include "thread.h"

void *thread_routine(void* Q)
{
	char *free_q; //declare for dequeue memory free
	int i = 0;
	while(1)
	{
	  	//pirintf("%s running \033[0;31mtime\033[0m : %d\n", (char*)thread_name, i);
		
		free_q = dequeue(Q);	 
	  	i++;
		
		if(free_q != NULL) {free(free_q); free_q = NULL;}

		sleep(1);
	}
}


int queue_empty(QUEUE q)
{
	if(q.head==q.tail) return 1;
	return 0;
}


void enqueue(QUEUE *q, char* data) 
{
	strcpy(q->arr[q->head++], data);
	//q->head--;
	//printf("PUSH : %s\n", q->arr[q->head]);
	q->head = q->head % MAX;
}


char* dequeue(QUEUE *q)
{
	char *data;
	data = (char*)calloc(STRLEN,sizeof(char));

	if(queue_empty(*q))
	{
	  	printf("queue is \033[0;33mempty!\033[0m\n");
		return 0;
	}
	strcpy(data, q->arr[q->tail++]);	
	printf("\033[0;31mPOP\033[0m : %s\n", data);
	q->tail = q->tail % MAX;

	return data;
}
