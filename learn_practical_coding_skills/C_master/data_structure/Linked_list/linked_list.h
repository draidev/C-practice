#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 32

//typedef struct linked_list{
//	Node *head;
//	Node *tail;
//	int size;
//}Linked_list;

typedef struct Node{
	char* data;
	struct Node* next;
}Node;


//void create_list(Linked_list *list);
//void free_list(Linked_list *list);
Node* append_node(char *data);
void show_list(Node *head);
void free_node(Node *head, int size);

#endif
