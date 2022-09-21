#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#ifndef THREAD_H
#define THREAD_H
#define MAX 3
#define STRLEN 64 

typedef struct queue{
	int head;
	int tail;
	int full_flag;
	char **arr;
}QUEUE;

void* thread_routine(void* data);
int queue_empty(QUEUE q);
int queue_full(QUEUE q);
void show_queue(QUEUE *q);
int enqueue(QUEUE* q, char* data);
char* dequeue(QUEUE* q);

#endif
