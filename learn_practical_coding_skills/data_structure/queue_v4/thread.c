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
		
		sleep(2);
	}
	
	return NULL;
}


int queue_empty(QUEUE q)
{
	if(q.head==q.tail && q.arr[q.tail][0]==0) return 1;
	
	return 0;
}


int queue_full(QUEUE q)
{
	if((q.tail - q.head == 1) || (q.head==(MAX-1) && q.tail==0)) {printf("head:%d tail:%d\n",q.head, q.tail); return 1;}
	
	return 0;
}

void show_queue(QUEUE *q)
{
	int i,j;

	if (q->full_flag == 0) q->full_flag = 0;

	printf("\n\033[0;35mqueue======================================================\033[0m\n");
	for(i = 0; i < MAX; i++)
	{		
		printf("\033[0;35m%d\033[0m  ",i);
		for(j = 0; j < (int)strlen(q->arr[i]); j++)
		{
			printf("%c", q->arr[i][j]);
		}
		if(i < MAX-1) printf("\t\033[0;35m||\033[0m  ");
	}
	printf("\n\033[0;35mqueue======================================================\033[0m\n");
}


int enqueue(QUEUE *q, char* data) 
{
	if(strcmp(data, "q")==0)
	{
		q->arr[q->head] = "q";
		return 0;
	}

	if(q->full_flag == 1)
	{	
		printf("\033[0;31mcan't push data, queue is full!!!\033[0m");
		printf("\ncant head : %d  tail : %d \n",q->head, q->tail);
		show_queue(q);

		return 0;
	}
	

	strcpy(q->arr[q->head], data);

	if(queue_full(*q))
	{
		if(q->full_flag == 0) q->full_flag = 1;
		
		show_queue(q);
		printf("queue is \033[0;34mfull\033[0m\n\n");
		
		q->head++;
		q->head = q->head % MAX;

		return 0;
	}
	
	q->head++;
	q->head = q->head % MAX;
	show_queue(q);
	//printf("push head,tail : %d %d\n", q->head, q->tail);
	
	return 1;
}


char* dequeue(QUEUE *q)
{
	char *data;

	if(q->full_flag == 1) q->full_flag = 0;
	if(queue_empty(*q))
	{
	  	printf("queue is \033[0;33mempty!\033[0m\n");
		return 0;
	}
	data = (char*)calloc(STRLEN,sizeof(char));
	strcpy(data, q->arr[q->tail]);	

	memset(q->arr[q->tail], 0, sizeof(char) * STRLEN);
	
	printf("\n\033[0;31mpop\033[0m : %s", data);
	q->tail++;
	q->tail = q->tail % MAX;
	//printf("pop head,tail : %d %d\n", q->head, q->tail);
	show_queue(q);
	
	return data;
}
