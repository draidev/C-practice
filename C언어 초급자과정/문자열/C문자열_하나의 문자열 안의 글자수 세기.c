#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[5] = "Love";
	char input1[5] = "A";
	char input2[5] = "B";
	char inputcopy[10] = "I love you";
	char result[5] = "Love";
	
	printf("�Է��� ���ڿ��� ���� : %d\n", strlen(input));
	printf("���ڿ� �� : %d\n",strcmp(input1,input2));
	strcpy(result, inputcopy);
	printf("���ڿ� ���� : %s\n", result);
	
	return 0;
} 
