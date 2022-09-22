#include "thread.h"

void *thread_routine(void* Q)
{
	int i = 0;
	while(1)
	{
	  	//pirintf("%s running \033[0;31mtime\033[0m : %d\n", (char*)thread_name, i);
		
		dequeue(Q);	  	
	  	i++;
		sleep(1);
	}
}


int queue_empty(QUEUE q)
{
	if(q.head==q.tail) return 1;
	return 0;
}


void enqueue(QUEUE *q, int data) 
{
	q->arr[q->head++] = data;
	printf("ENQUEUE : %d\n", data);
	q->head = q->head % MAX;
}


int dequeue(QUEUE *q)
{
	int data;

	if(queue_empty(*q))
	{
	  	printf("queue is empty!\n");
		return -1;
	}

	data = q->arr[q->tail++];
	printf("DEQUEUE : %d\n", data);
	q->tail = q->tail % MAX;
	
	return data;
}
