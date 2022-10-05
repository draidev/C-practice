#include "hash_table.h"

/* json & TLS function */
jp_t* get_json_conf(jp_t *jp){
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	JSON_Object *arrayObject;
	JSON_Array *rootArray;
	char temp[STRLEN];
	int i, num;

	rootValue = json_parse_file("thread.json");
	rootObject = json_value_get_object(rootValue);
	num = (int)json_object_get_number(rootObject, "thread_num");
	
	jp = JSON_Parser_alloc(jp, num);

	rootArray = json_object_get_array(rootObject, "thread");
	for(i = 0; i < num; i++){
		(jp+i)->thread_num = num;
		
		arrayObject = json_array_get_object(rootArray, i);
		(jp+i)->thread_option = (int)json_object_get_number(arrayObject, "thread_option");
		
		strcpy(temp, json_object_get_string(arrayObject, "name"));
		strncpy((jp+i)->thread_name, temp, strlen(temp)+1);
		strcpy(temp, json_object_get_string(arrayObject, "hash_file"));
		strncpy((jp+i)->hash_file, temp, strlen(temp)+1);
	}
	
	json_value_free(rootValue);

	return jp;
}


jp_t* JSON_Parser_alloc(jp_t *jp, int num){
	int i;
	jp = (jp_t*)calloc(num, sizeof(jp_t));
	if(jp) printf("success jp alloc!!\n");
	else printf("fail jp alloc!!\n"); 

	for(i = 0; i < num; i++){
		(jp+i)->hash_file = (char*)calloc(sizeof(char), STRLEN);
		(jp+i)->thread_name = (char*)calloc(sizeof(char), STRLEN);
	}

	return jp;
}

void JSON_Parser_free(jp_t *jp){
	int i;

	for(i = 0; i < jp->thread_num; i++){
		if((jp+i)->hash_file != NULL){
			free((jp+i)->hash_file);
			(jp+i)->hash_file = NULL;
		}
		else
			printf("hash_file free error!\n");

		if((jp+i)->thread_name){
			free((jp+i)->thread_name);
			(jp+i)->thread_name = NULL;
		}
		else
			printf("thread_name free error!\n");
	}

	if(jp != NULL){
		free(jp);
		jp = NULL;
	}
	else printf("jp free error!\n"); 
}

/* thread function */
__thread hash_table_t TLS_hash[HASHLEN]; //declare TLS here!!
void *thread_routine(void *jp){
	FILE *hash_csv = NULL;
	char str_tmp[STRLEN];
	char file_name[STRLEN];
	char thread_name[STRLEN];
	int j, num = 0, option = 0;
	jp_t *temp_jp = (jp_t*)jp;

	temp_jp->sleep_flag = 0;
	temp_jp->done_flag = 0;
	
	num = temp_jp->thread_num;
	option = temp_jp->thread_option;
	strncpy(file_name, temp_jp->hash_file, strlen(temp_jp->hash_file)+1);
	strncpy(thread_name, temp_jp->thread_name, strlen(temp_jp->thread_name)+1);

	printf("num : %d option : %d file_name : %s thread_name : %s\n", num, option, file_name, thread_name); 
	
	hash_table_alloc(TLS_hash);
	hash_csv = fopen(file_name, "r");
	if(hash_csv)
		while(fgets(str_tmp, STRLEN, hash_csv) != NULL){
			for(j = 0; j < option; j++){
				temp_jp->sleep_flag = 1;
				sleep(1);
			}
			temp_jp->sleep_flag = 0;
			sleep(1);

			append_list(TLS_hash, str_tmp);
		}
	else
		fprintf(stderr, "fileopen error!!\n");

	temp_jp->done_flag = 1;
	temp_jp->sleep_flag = 1;
	
			
			
	printf("\n\n\n\n\033[0;34m==================================================================================\033[0m\n");
	printf("\033[0;34m%s\033[0m\n", temp_jp->thread_name);
	show_hash_table(TLS_hash);
	printf("\033[0;34m============================================================================================\033[0m\n");

	fclose(hash_csv);
	linked_list_free(TLS_hash);
	TLS_free(TLS_hash);
	return 0;
}


int check_sleep_flag(jp_t *jp){
	if(jp->sleep_flag == 1)
		return 1;		
	else
		return 0;
}


/* hash table function*/
void* hash_table_alloc(hash_table_t *hash_tbl){
	//hash_tbl = (hash_table_t*)calloc(sizeof(hash_table_t), HASHLEN);
	//	if(hash_tbl) printf("success alloc!\n");
	//	else printf("alloc fail!\n");

	int i;
	for(i = 0; i < HASHLEN; i++){
		(hash_tbl+i)->head = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
		(hash_tbl+i)->tail = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
		(hash_tbl+i)->list_entry = 0;
	}

	return hash_tbl;
}


void show_hash_table(hash_table_t *hash_tbl){
	int i;
	
	

	for(i = 0; i < HASHLEN; i++){
		int j = 0;
		if((hash_tbl+i)->list_entry > 0){
			linked_list_t *s_node = (hash_tbl + i)->head;

			printf("\033[0;35mHASH=TABLE==================================================================================\033[0m\n");
			while(1){
				j++;
				s_node = s_node->next;
				printf("%d || hash_index : %d || hash_key : %s || data : %s\n", j, i, s_node->hash_key, s_node->data);
				if(s_node->next == NULL)
					break;
			}
			printf("\033[0;35mHASH=TABLE==================================================================================\033[0m\n\n");
		}
		else
			continue;
	}
}


void append_list(hash_table_t *hash_tbl, char* str_tmp){
	linked_list_t *newnode;
	newnode = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
	int hash_index;

	if(newnode){
		hash_key_n_data_alloc(newnode);
		set_linked_list(newnode, str_tmp);
		hash_index = get_hash_index(newnode->hash_key);
		
		if((hash_tbl+hash_index)->list_entry == 0){
			(hash_tbl+hash_index)->head->next = newnode;
			(hash_tbl+hash_index)->tail->next = newnode;
			(hash_tbl+hash_index)->list_entry++;
			newnode->next = NULL;
		}
		else{
			(hash_tbl+hash_index)->tail->next->next = newnode;
			(hash_tbl+hash_index)->tail->next = newnode;
			(hash_tbl+hash_index)->list_entry++;
			newnode->next = NULL;
		}
	}
	else
		fprintf(stderr, "create node error!!");
}


void hash_key_n_data_alloc(linked_list_t *newnode){
	if(newnode->hash_key == NULL)
		newnode->hash_key = (char*)calloc(sizeof(char), KEYLEN);
	else
		fprintf(stderr, "hash_key alloc error!!");

	if(newnode->data == NULL)
		newnode->data = (char*)calloc(sizeof(char), DATALEN);
	else
		fprintf(stderr, "data alloc error!!");
}


void set_linked_list(linked_list_t *newnode, char *str){
	char *p;

	p = strtok(str, ", ");
	strncpy(newnode->hash_key, p, strlen(p)+1);

	p = strtok(NULL, "\n");
	strncpy(newnode->data, p, strlen(p)+1);

	newnode->next = NULL;
}


int get_hash_index(char* str){
	int hash_index = 0;
	int i = 0;

	while(i < (int)strlen(str)){
		hash_index += (int)(str[i]);
		i++;
	}
	return hash_index % HASHLEN;
}


void hash_table_free(hash_table_t *hash_tbl){
	int i;
	
	for(i = 0; i < HASHLEN; i++){
		if((hash_tbl+i)->head){
			free((hash_tbl+i)->head);
			(hash_tbl+i)->head = NULL;
		}
		if((hash_tbl+i)->tail){
			free((hash_tbl+i)->tail);
			(hash_tbl+i)->tail = NULL;
		}
	}

	if(hash_tbl){
		free(hash_tbl);
		hash_tbl = NULL;
	}	
}


void TLS_free(hash_table_t *hash_tbl){
	int i;

	for(i = 0; i < HASHLEN; i++){
		if((hash_tbl+i)->head){
			free((hash_tbl+i)->head);
			(hash_tbl+i)->head = NULL;
		}
		if((hash_tbl+i)->tail){
			free((hash_tbl+i)->tail);
			(hash_tbl+i)->tail = NULL;
		}
	}
}


void linked_list_free(hash_table_t *hash_tbl){
	linked_list_t *f_node;
	linked_list_t *f_next;
	int i, j;

	for(i = 0; i < HASHLEN; i++)
	{
		if((hash_tbl+i)->head->next)
			f_node = (hash_tbl+i)->head->next;
		else
			continue;

		f_next = f_node->next;

		for(j = 0; j < (hash_tbl + i)->list_entry; j++){
			if(f_node->hash_key){
				free(f_node->hash_key);
				f_node->hash_key = NULL;
			}
	
			if(f_node->data){
				free(f_node->data);
				f_node->data = NULL;
			}

			if(f_node){
				free(f_node);
				f_node = NULL;
			}

			if(f_next){
				f_node = f_next;
				f_next = f_node->next;
			}
			else{
				f_next = NULL;
				break;
			}
		}
	}
}

