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

void *thread_routine(void* name);

void print_json()
{
	JSON_Value *printValue = json_parse_file("output.json");
	size_t repeat_size = json_serialization_size_pretty(printValue);
	char *buf = (char*)malloc(sizeof(char) * repeat_size);
	json_serialize_to_buffer_pretty(printValue, buf, repeat_size);
	printf("%s\n", buf);
	free(buf);	
}

int main(void){
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	JSON_Value *outValue;
	JSON_Object *outObject;
	JSON_Value *newValue;
	JSON_Object *newObject;
	JSON_Object *threadObject;
	JP jp; 
	int i, j, rand_num, thread_name_len;
	char low_a = 'a';
	char upp_a = 'A';
	char *rand_ch;
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
	threadObject = json_array_get_object(thread, 0);
	thread_name_len = strlen(json_object_get_string(threadObject, "name"));
	// allocation memory for thread name
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
	
	pthread = (pthread_t*)malloc(sizeof(pthread_t)*jp.thread_num);
	for(i = 0; i < jp.thread_num; i++)
	{
		pthread_create(pthread+i, NULL, thread_routine,(void *)*(p+i));
	}



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


	for(i = 0; i < jp.thread_num; i++)
	{
		pthread_join(*(pthread+i), NULL);	
	}
		
	// free thread memory
	for (i = 0; i < jp.thread_num; i++)
	{
		free(*(p+i));
	}
	free(p);
	free(pthread);
	//  /* 해제 */
	json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제
	json_value_free(outValue);
	return 0;
}


void* thread_routine(void* name){
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


