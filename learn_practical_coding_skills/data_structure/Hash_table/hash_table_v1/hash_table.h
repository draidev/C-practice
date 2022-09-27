#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHLEN 31
#define KEYLEN 32
#define DATALEN 128
#define STRLEN 256

typedef struct linked_list{
	struct linked_list *next;
	char *hash_key;
	char *data;
}linked_list_t;

typedef struct hash_table{
	struct linked_list *head;
	struct linked_list *tail;
	int list_entry;
}hash_table_t;

void hash_table_alloc(hash_table_t *hash_tbl);
void hash_table_free(hash_table_t *hash_tbl);
void linked_list_free(hash_table_t *hash_tbl);
void append_list(hash_table_t *hash_tbl, char* str_tmp); 
void hash_key_n_data_alloc(linked_list_t *newnode);
void set_linked_list(linked_list_t *newnode, char *str);
int get_hash_index(char* str);


#endif
