#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#include "parson/parson.h"

#define STRLEN 16

typedef struct JSON_Parser{
	int repeat;
	int thread_num;
}JP;


static JSON_Value *rootValue;
static JSON_Object *rootObject;
static JSON_Value *outValue;
static JSON_Object *outObject;
static JSON_Value *newValue;
static JSON_Object *newObject;
static JSON_Object *threadObject;
static JSON_Array *repeat;
static JSON_Object *sigObject;
static JSON_Value *sigValue;
JP jp;

static void* thread_routine(void* name){
        int i=0;
	char* thread_name = (char*)name;

        while(1)
	{
                printf("%s running time : %ds\n",thread_name,i);
		i++;
                sleep(1);
        }
	return 0;
}

static int get_thread_name_len(JSON_Array *thread)
{
	threadObject = json_array_get_object(thread, 0);	
	return strlen(json_object_get_string(threadObject, "name"));
}

static char* generate_random_char(char *rand_ch)
{
	char low_a = 'a';
	char upp_a = 'A';
	int rand_num, i, j;

	for(i = 0; i < jp.repeat; i++)
	{
		for(j = 0; j < STRLEN; j++)
		{
			rand_num = rand();
			if(rand_num % 2 == 0) rand_ch[j] = (char)(low_a + rand_num % 26);
			else rand_ch[j] = (char)(upp_a + rand_num % 26);
		}
	}
	return rand_ch;
}

static void json_set_rand_ch(void)
{
	int i;
	char* rand_ch;

	// get repeat_cnt and write in output file
	json_object_set_number(outObject, "repeat_cnt", jp.repeat);
	json_object_set_value(outObject, "repeat", json_value_init_array());
	repeat = json_object_get_array(outObject, "repeat");	
	
	printf("=============random func operating===========\n");
	
	for(i = 0; i < jp.repeat; i++)
	{	
		rand_ch = (char*)malloc(sizeof(char) * STRLEN);
		generate_random_char(rand_ch);

		newValue = json_value_init_object();
		newObject = json_value_get_object(newValue);
		json_object_set_string(newObject, "random_string", rand_ch);
		json_array_append_value(repeat, newValue);
		
		free(rand_ch);
		rand_ch = NULL;
	}
}

static void print_json(int signo)
{
	if(signo == SIGINT)
	{
		printf("\n\n\n==============================\n");
		printf("generating JSON output file...");		
		printf("\n==============================\n\n\n");

		outValue = json_value_init_object();
		outObject = json_value_get_object(outValue);
		rootValue = json_parse_file("jparser.json");
		rootObject = json_value_get_object(rootValue);
		jp.repeat = json_object_get_number(rootObject, "repeat");
		json_set_rand_ch();
		json_serialize_to_file_pretty(outValue, "output.json");

		JSON_Value *printValue = json_parse_file("output.json");
		size_t repeat_size = json_serialization_size_pretty(printValue);
		char *buf = (char*)malloc(sizeof(char) * repeat_size);
		json_serialize_to_buffer_pretty(printValue, buf, repeat_size);
		printf("%s\n", buf);
		

		free(buf);
		buf = NULL;

		sleep(3);
		exit(0);
	}
}

static void reload_json(int signo)
{
	if(signo == SIGUSR1)
	{
		printf("\n\n=======================");
		printf("\nsignal SIGUSR1 received\n");
		printf("=======================\n\n");
		if(outValue)
		{
			json_value_free(outValue);	
			outValue = NULL;
		}
			
		sigValue = json_parse_file("jparser_sig.json");
		sigObject = json_value_get_object(sigValue);
		rootValue = json_parse_file("jparser.json");
		rootObject = json_value_get_object(rootValue);
		
		sigObject = json_object_get_object(sigObject, "reload");
		json_object_set_number(rootObject, "repeat", json_object_get_number(sigObject, "repeat"));

		json_serialize_to_file_pretty(rootValue, "jparser.json");

		size_t repeat_size = json_serialization_size_pretty(rootValue);
		char *buf = (char*)malloc(sizeof(char) * repeat_size);
		json_serialize_to_buffer_pretty(rootValue, buf, repeat_size);
		printf("%s\n", buf);


		free(buf);
		buf = NULL;
		json_value_free(sigValue);
		sigValue = NULL;
		json_value_free(rootValue);
		rootValue = NULL;
	}
}


int main(void){
	int i, thread_name_len;
	pthread_t *pthread;
	JSON_Array *thread;
	char **p;


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
	thread_name_len = get_thread_name_len(thread);

	p = (char**)malloc(sizeof(char*)*jp.thread_num);
	for (i = 0; i < jp.thread_num; i++)
	{
		*(p+i) = (char*)malloc(sizeof(char)*thread_name_len);
	}

	for(i = 0; i < jp.thread_num; i++)
	{
		threadObject = json_array_get_object(thread, i);
		strcpy((*(p + i)), json_object_get_string(threadObject, "name"));
	}
	
	// allocation and create thread
	pthread = (pthread_t*)malloc(sizeof(pthread_t)*jp.thread_num);
	for(i = 0; i < jp.thread_num; i++)
	{
		pthread_create(pthread+i, NULL, thread_routine,(void *)*(p+i));
	}


	//   /* generate random character */
	json_set_rand_ch();

	// make output file	
	json_serialize_to_file_pretty(outValue, "output.json");

	signal(SIGUSR1, reload_json);
	signal(SIGINT, print_json);
	
	while(1);

	for(i = 0; i < jp.thread_num; i++)
	{
		pthread_join(*(pthread+i), NULL);	
	}
		

	//  /* 해제 */
	for (i = 0; i < jp.thread_num; i++)
	{
		free(*(p+i));
	}
	free(p);
	free(pthread);
	json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제
	json_value_free(outValue);
	json_value_free(newValue);
	return 0;
}
