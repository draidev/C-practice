#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListStack{
    int data;
    struct ListStack *next;
} Stack;


int main(void) {
    int line;
    char input_str[512] = {0, };
    char *tok_str;
    char *tok_x;
    int x;
    scanf("%d", &line);

    for (int i = 0; i < line; i++) {
        scanf("%s", &input_str);
        tok_str = strtok(input_str, " ");
        while(tok_str != NULL) {
            tok_x = strtok(NULL, " ");
        }
        if (tok_x != NULL) x = atoi(tok_x);

        memset(input_str, 0, 512);
    }

    return 0;
} 