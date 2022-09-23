#include "linked_list.h"

//void create_list(Linked_list *list){
//	list->head = (Node*)malloc(sizeof(Node));
//	list->head->next = list->head;
//	list->size = 0;
//}


//void free_list(Linked_list *list){
//	free(list);
//}


Node* append_node(char *data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(sizeof(char)*STRLEN);

	newNode->next = NULL;
	strcpy(newNode->data, data);

	return newNode;
}


void show_list(Node *head){
	int i = 0;
	Node *s_node = head->next;

	printf("\033[0;35mLINKED==========================LIST\033[0m\n\n");
	printf("\033[0;35m%d\033[0m : %s \033[0;33m-> \033[0m", ++i, s_node->data);

	while(1){
		i++;
		s_node = s_node->next;
		printf("\033[0;35m%d\033[0m : %s " , i, s_node->data);
		
		if(s_node->next != NULL)
			printf("\033[0;33m-> \033[0m");
		else		
			printf("\033[0;33m-> \033[0m\033[0;31mNULL\033[0m");

		if(s_node->next == NULL)
			break;
	}
	printf("\n\n\033[0;35mLINKED==========================LIST\033[0m\n");
}


void free_node(Node *head, int size){
	Node *f_node;
	Node *f_next;
	int i;

	f_node = head->next;
	f_next = f_node->next;
	
	for(i = 0; i < size; i++){
		free(f_node->data);
		free(f_node);
		
		f_node = f_next;
	
		printf("%d \033[0;34mfree \033[0m", i+1);
		if(f_node->next != NULL){
			printf("\033[0;33m-> \033[0m");
			f_next = f_node->next;
		}
	}
	printf("\n\n");
}
