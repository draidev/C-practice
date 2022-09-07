#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "parson/parson.h"


int main(){
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	JSON_Value *outValue;
	JSON_Object *outObject;
	int i, re_cnt, rand_num;
	char low_a = 'a';
	char upp_a = 'A';
	char rand_ch[2];
	rand_ch[1] = '\0';

	srand((unsigned int)time(NULL));

	/* 초기화 */
	rootValue = json_parse_file("jparser.json");      // JSON 파일을 읽어서 파싱
	rootObject = json_value_get_object(rootValue);    // JSON_Value에서 JSON_Object를 얻음
	outValue = json_value_init_object();
	outObject = json_value_get_object(outValue);

	re_cnt = json_object_get_number(rootObject, "repeat");
	json_object_set_number(outObject, "repeat_cnt", re_cnt);
	json_object_set_value(outObject, "repeat", json_value_init_array());
	JSON_Array *repeat = json_object_get_array(outObject, "repeat");
	
	for(i = 0; i < re_cnt; i++)
	{
		rand_num = rand();
		// choose lower or upper character
		if(rand_num%2 == 0)
			rand_ch[0] = (char)(low_a + rand_num % 26);
		else	
			rand_ch[0] = (char)(upp_a + rand_num % 26);
		json_value_init_string("aa");
		json_array_append_string(repeat, rand_ch);
	}

	json_serialize_to_file_pretty(outValue, "output.json");
	//  /* 해제 */
	json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제

	return 0;
}
