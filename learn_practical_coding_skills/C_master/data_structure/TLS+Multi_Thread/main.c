/*
 *
 * make hash table with TLS
 *
 *
 */



#include "hash_table.h"


int main(void){
	pthread_t *pthread; 
	jp_t *jp = NULL;
	int i;
	int break_flag = 0;

	jp = get_json_conf(jp);	

	pthread = (pthread_t*)calloc(sizeof(pthread_t), jp->thread_num);

	for (i = 0; i < jp->thread_num; i++){
		printf("%s : \033[0;32mINIT\033[0m\n", (jp+i)->thread_name); 
		pthread_create(pthread+i, NULL, thread_routine, jp+i);
	}

	while(1){
		if(break_flag == jp->thread_num)
			break;

		sleep(1);

		for(i = 0; i < jp->thread_num; i++){
			if((jp+i)->done_flag == 1){
				printf("\n\033[0;36m%s\033[0m \033[0;35mDONE\033[0m\n\n", (jp+i)->thread_name);
				break_flag++;
				(jp+i)->done_flag = -1;
			}
			else if((check_sleep_flag(jp+i)))
				printf("\033[0;36m%s\033[0m \033[0;33mSLEEP\033[0m\n",(jp+i)->thread_name);
			else
				printf("\033[0;36m%s\033[0m \033[0;32mRUNNING\033[0m\n", (jp+i)->thread_name);
		}
		printf("\n");
	}


	for(i = 0; i < jp->thread_num; i++){
		pthread_join(*(pthread + i), NULL);
	}

	JSON_Parser_free(jp);
	free(pthread);

return 0;
}
