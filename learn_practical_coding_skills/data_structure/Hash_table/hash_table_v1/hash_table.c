#include "hash_table.h"

void hash_table_alloc(hash_table_t *hash_tbl){
	if(hash_tbl == NULL)
		hash_tbl = (hash_table_t*)calloc(sizeof(hash_table_t), HASHLEN);
	else
		fprintf(stderr,  "alloc error!");

	int i;
	for(i = 0; i < HASHLEN; i++)
		hash_tbl[i].list_entry = 0;
}


void linked_list_alloc(linked_list_t *lnk_lst){
	if(lnk_lst == NULL)
		lnk_lst = (linked_list_t*)calloc(sizeof(linked_list_t), HASHLEN);
	else
		fprintf(stderr, "linked_list alloc error!!");

	if(lnk_lst->hash_key == NULL)
		lnk_lst->hash_key = (char*)calloc(sizeof(char), KEYLEN);
	else
		fprintf(stderr, "hash_key alloc erroe!!");

	if(lnk_lst->data == NULL)
		lnk_lst->data = (char*)calloc(sizeof(char), DATALEN);
	else
		fprintf(stderr, "data alloc erroe!!");
}


void hash_table_free(hash_table_t *hash_tbl){
	if(hash_tbl != NULL){
		free(hash_tbl);
		hash_tbl = NULL;
	}
}


void linked_list_free(linked_list_t *lnk_lst){
	if(lnk_lst->hash_key == NULL){
		free(lnk_lst->hash_key);
		lnk_lst->hash_key = NULL;
	}

	if(lnk_lst->data != NULL){
		free(lnk_lst->data);
		lnk_lst->data = NULL;
	}

	if(lnk_lst != NULL){
		free(lnk_lst);
		lnk_lst = NULL;
	}
}


int get_hash_index(char* str){
	int hash_index = 0;
	int i;

	while(str[i] != '\0'){
		hash_index += (int)(str[i]);
		i++;
	}

	return hash_index % HASHLEN;
}


void get_hashkey_n_data(FILE *hash_csv, hash_table_t *hash_tbl, linked_list_t *lnk_lst){
	char str_tmp[STRLEN];
	int hash_index;
	linked_list_t *temp_lnk_lst[HASHLEN];	
	int i = 0;

	if(hash_csv != NULL){
		while(fgets(str_tmp, STRLEN, hash_csv) != NULL){
			printf("str_tmp : %s", str_tmp);
			
			set_linked_list(lnk_lst+i, str_tmp);
			hash_index = get_hash_index((lnk_lst+i)->hash_key);
			
			if((hash_tbl + hash_index)->list_entry == 0){
				(hash_tbl + i)->head = lnk_lst+i;
				(temp_lnk_lst + hash_index)->next = (hash_tbl+hash_index)->head->next;
			}
			else{
				(temp_lnk_lst + hash_index)->next = lnk_lst+i;
				(temp_lnk_lst + hash_index) = lnk_lst+i;
			}

			(hash_tbl + i)->list_entry++;
			i++;
		}
	}
}


void set_linked_list(linked_list_t *lnk_lst, char *str){
	char *p;

	p = strtok(str, ", ");
	strncpy(lnk_lst->hash_key, p, STRLEN);

	p = strtok(NULL, ", ");
	strncpy(lnk_lst->data, p, STRLEN);

	lnk_lst->next = NULL;
}

