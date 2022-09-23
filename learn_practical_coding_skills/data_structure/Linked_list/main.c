#include "linked_list.h"

int main(void){
	char *input;
	Node *head;
	int size = 0;

	//create_list(&list);
	input = (char*)malloc(sizeof(char)*STRLEN);
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	scanf("%s",input);
	head->next = append_node(input);
	size++;

	Node *node = head->next;
	while(scanf("%s",input)==1){
		if(strcmp(input,"q")==0) break;
		node->next = append_node(input);
		node = node->next;
		size++;
	}

	show_list(head);
//	node = head->next;
//	printf("check before while: %s \n", head->next->data);
//	while(node->next != NULL){
//		printf("%s\n", node->data);
//		//printf("node3 %s\n",node->next->data);
//		node = node->next;
//		printf("node2 %s\n",node->data);
//	}

	free_node(head, size);
	//free(list);
	free(input);
	free(head);

	return 0;
}
