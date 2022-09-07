#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[5] = "Love";
	char input1[5] = "A";
	char input2[5] = "B";
	char inputcopy[10] = "I love you";
	char result[5] = "Love";
	
	printf("입력한 문자열의 길이 : %d\n", strlen(input));
	printf("문자열 비교 : %d\n",strcmp(input1,input2));
	strcpy(result, inputcopy);
	printf("문자열 복사 : %s\n", result);
	
	return 0;
} 
