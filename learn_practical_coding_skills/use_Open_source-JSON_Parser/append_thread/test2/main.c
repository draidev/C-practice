#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "parson/parson.h"

#define STRLEN 16

typedef struct JSON_Parser{
	int repeat;
	int thread_num;
}JP;

void *p_function(char *data);


int main(void){
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	JSON_Value *outValue;
	JSON_Object *outObject;
	JSON_Value *newValue;
	JSON_Object *newObject;
	JSON_Object *threadObject;
	JP jp; 
	int i, j, rand_num;
	char low_a = 'a';
	char upp_a = 'A';
	char *rand_ch;
	pthread_t pthread[2];
	int thr_id[2];
	JSON_Array *thread;
	char p[2][10];

	srand((unsigned int)time(NULL));
	
	/* 초기화 */
	rootValue = json_parse_file("jparser.json");
	rootObject = json_value_get_object(rootValue);
	outValue = json_value_init_object();
	outObject = json_value_get_object(outValue);
	
	// get structure value repeat, thread_num
	jp.repeat = json_object_get_number(rootObject, "repeat");
	jp.thread_num = json_object_get_number(rootObject, "thread_num");
	if (jp.thread_num < 1)
	{	
		printf("thread not found. exit.\n");
		exit(1);
	}

	printf("repeat : %d thread_num : %d\n", jp.repeat, jp.thread_num);
	// get thread name
	thread = json_object_get_array(rootObject, "thread");
	for(i = 0; i < jp.thread_num; i++)
	{
		threadObject = json_array_get_object(thread, i);
		strcpy(p[i], json_object_get_string(threadObject, "name"));
		printf("thread name %d : %s\n", i+1, p[i]);
	}
	
	thr_id[0] = pthread_create(&pthread[0], NULL, p_function(p[0]), (void*)p[0]);
	printf("thread id1 : %lx \n", pthread[0]);
	if (thr_id[0] < 0)
	{
		perror("thread create error");
		exit(EXIT_FAILURE);
	}
	printf("thread111111111111111111end\n");
	
	thr_id[1] = pthread_create(&pthread[1], NULL, p_function(p[1]), (void*)p[1]);
	printf("thread id2 : %lx \n", pthread[1]);
	if (thr_id[1] < 0)
	{
		perror("thread create error");
		exit(EXIT_FAILURE);
	}

	printf("main tid:%lx\n",pthread_self());
	for (i = 0; i < 5; i++)
	{
		printf("main:%d\n",i);
		sleep(1);
	}
	//for(i = 0; i < jp->thread_num; i++)
	//	free(p1[i]);
	free(thread);
	// get repeat_cnt and write in output file
	json_object_set_number(outObject, "repeat_cnt", jp.repeat);
	json_object_set_value(outObject, "repeat", json_value_init_array());
	JSON_Array *repeat = json_object_get_array(outObject, "repeat");	


	//   /* generate random character */
	for(i = 0; i < jp.repeat; i++)
	{
		rand_ch = (char *)malloc(sizeof(char) * STRLEN);
		for (j = 0; j < 16; j++)
		{
			rand_num = rand();
			// choose lower or upper character
			if(rand_num%2 == 0)
				rand_ch[j] = (char)(low_a + rand_num % 26);
			else	
				rand_ch[j] = (char)(upp_a + rand_num % 26);
		}
		newValue = json_value_init_object();
		newObject = json_value_get_object(newValue);
		json_object_set_string(newObject, "random_string", rand_ch);
		json_array_append_value(repeat, newValue);
		
		free(rand_ch);
		rand_ch = NULL;
	}
	
	json_serialize_to_file_pretty(outValue, "output.json");

	//  /* 해제 */
	json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제
	json_value_free(outValue);
	return 0;
}



void *p_function(char *data)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	char* thread_name = (char *)data;
	int i = 0;
	
	for(i = 0; i < 8; i++)
	{
		printf("\t%s running time : %ds\n",thread_name, i);
		printf("\ttid : %x, pid : %u\n", (unsigned int)tid, (unsigned int)pid);
		sleep(1);
	}

	return 0;
}
