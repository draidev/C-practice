#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#ifndef THREAD_H
#define THREAD_H
#define MAX 10
#define STRLEN 256

typedef struct queue{
	int head;
	int tail;
	int arr[MAX];
}QUEUE;

void* thread_routine(void* data);
int queue_empty(QUEUE q);
void enqueue(QUEUE* q, int data);
int dequeue(QUEUE* q);

#endif
