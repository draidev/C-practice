#include "hash_table.h"

void* hash_table_alloc(hash_table_t *hash_tbl){
	hash_tbl = (hash_table_t*)calloc(sizeof(hash_table_t), HASHLEN);
			
	if(hash_tbl) printf("success alloc!\n");
	else printf("alloc fail!\n");

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
			printf("HASH=TABLE==================================================================================\n\n");
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
	strncpy(newnode->hash_key, p, strlen(p));

	p = strtok(NULL, "\n");
	strncpy(newnode->data, p, strlen(p));

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

