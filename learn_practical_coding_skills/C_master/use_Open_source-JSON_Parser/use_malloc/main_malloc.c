#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "parson.h"

#define STRLEN 16

typedef struct JSON_Parser{
	int repeat;
	int thread_num;
}JP;

int main(void){
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	JSON_Value *outValue;
	JSON_Object *outObject;
	JSON_Value *newValue;
	JSON_Object *newObject;
	JP jp; 
	int i, j, rand_num;
	char low_a = 'a';
	char upp_a = 'A';
	char *rand_ch;

	srand((unsigned int)time(NULL));
	
	/* 초기화 */
	rootValue = json_parse_file("jparser.json");
	rootObject = json_value_get_object(rootValue);
	outValue = json_value_init_object();
	outObject = json_value_get_object(outValue);

	jp.repeat = json_object_get_number(rootObject, "repeat");
	jp.thread_num = json_object_get_number(rootObject, "thread_num");
	printf("repeat : %d thread_num : %d\n", jp.repeat, jp.thread_num);
	
	json_object_set_number(outObject, "repeat_cnt", jp.repeat);
	json_object_set_value(outObject, "repeat", json_value_init_array());
	JSON_Array *repeat = json_object_get_array(outObject, "repeat");
	
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
