#include "hash_table.h"

void hash_table_alloc(hash_table_t *hash_tbl){
	hash_tbl = (hash_table_t*)calloc(sizeof(hash_table_t), HASHLEN);
			
	if(hash_tbl) printf("success alloc!\n");
	else printf("alloc fail!\n");

	int i;
	for(i = 0; i < HASHLEN; i++){
		(hash_tbl+i)->head = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
		(hash_tbl+i)->tail = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
		(hash_tbl+i)->list_entry = 0;
		printf("alloc entry %d\n", (hash_tbl+i)->list_entry);
	}
}


void append_list(hash_table_t *hash_tbl, char* str_tmp){
	linked_list_t *newnode = (linked_list_t*)calloc(sizeof(linked_list_t), 1);
	int hash_index;

	if(newnode){
		hash_key_n_data_alloc(newnode);
		set_linked_list(newnode, str_tmp);
		hash_index = get_hash_index(newnode->hash_key);
		
		printf("hash_key : %s\n", newnode->hash_key);
		printf("data : %s\n", newnode->data);
		printf("index : %d\n", hash_index);
		printf("entry : %d\n", (hash_tbl+1)->list_entry); // core dump!!!!!


		if((hash_tbl+hash_index)->list_entry == 0){
			printf("test\n");
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
	strncpy(newnode->hash_key, p, STRLEN);

	p = strtok(NULL, ", ");
	strncpy(newnode->data, p, STRLEN);

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
		free((hash_tbl+i)->head);
		free((hash_tbl+i)->tail);
	}
}


void linked_list_free(hash_table_t *hash_tbl){
	linked_list_t *f_node;
	linked_list_t *f_next;
	int i, j;

	for(i = 0; i < HASHLEN; i++)
	{
		f_node = (hash_tbl+i)->head->next;
		f_next = f_node->next;

		for(j = 0; j < (hash_tbl+j)->list_entry; j++){
			free(f_node);
			f_node = f_next;
	
			if(f_node->next != NULL)
				f_next = f_node->next;
		}
	}
}

