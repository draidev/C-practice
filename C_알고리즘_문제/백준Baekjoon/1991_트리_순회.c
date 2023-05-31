#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    char data;
    struct _node *left;
    struct _node *right;
}node;

node *makeNode(char ch) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = ch;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *searchNode(node* t, char ch) {
    if (t != NULL) {
        if (t->data == ch) return t;
        else {
            searchNode(t->left, ch);
            searchNode(t->right, ch);
        }
    }
    else return NULL;
}

void setNode(node* t, char ch1, char ch2, char ch3) {
    node *temp = searchNode(t, ch1);
    if (temp != NULL) {
        temp->left = makeNode(ch2);
        temp->right = makeNode(ch3);
    }
}

void preorder_traverse(node* t) {
    if (t != NULL) {
        printf("%c", t->data);
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}

int main(void) {
    int n;
    char ch1, ch2, ch3;

    scanf("%d", &n);
    node *root = makeNode('A');
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &ch1, &ch2, &ch3);
        setNode(root, ch1, ch2, ch3);
    }

    preorder_traverse(root);

    return 0;
}