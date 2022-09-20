#include "thread.h"

void *thread_routine(void* Q)
{
	char *free_q; //declare for dequeue memory free
	int i = 0;
	while(1)
	{
	  	//printf("%s running \033[0;31mtime\033[0m : %d\n", (char*)thread_name, i);
			
		free_q = dequeue(Q);	 
	  	if(free_q && strcmp(free_q, "q")==0)
		{
			free(free_q);
			break;
		}
		i++;
		//printf("free_q : %s\n", free_q);
		free(free_q);
		free_q = NULL;
		
		sleep(1);
	}
	
	return NULL;
}


int queue_empty(QUEUE q)
{
	if(q.head==q.tail) return 1;
	return 0;
}


void enqueue(QUEUE *q, char* data) 
{
	strcpy(q->arr[q->head++], data);
	q->head = q->head % MAX;
}


char* dequeue(QUEUE *q)
{
	char *data;
	if(queue_empty(*q))
	{
	  	printf("queue is \033[0;33mempty!\033[0m\n");
		return 0;
	}

	data = (char*)calloc(STRLEN,sizeof(char));

	strcpy(data, q->arr[q->tail++]);	
	printf("\033[0;31mPOP\033[0m : %s\n", data);
	q->tail = q->tail % MAX;

	return data;
}
