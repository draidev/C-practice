/*
 *
 * make hash table with TLS
 *
 *
 */



#include "hash_table.h"


int main(void){
	pthread_t *pthread; 
	jp_t jp;
	int i;

	get_json_conf(&jp);
	printf("thread_num : %d\n", jp.thread_num);

	pthread = (pthread_t*)calloc(sizeof(pthread_t), jp.thread_num);

	for (i = 0; i < jp.thread_num; i++){
		pthread_create(pthread+i, NULL, thread_routine, *(jp.thread_name+i));
		if(pthread+i)
			printf("%s : INIT\n", ); 
	}


	for(i = 0; i < jp.thread_num; i++){
		pthread_join(*(pthread + i), NULL);
	}

	JSON_Parser_free(&jp);

return 0;
}
