#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	char fname[20];
	char fname1[20];
	char capi[] = "_capital.txt";
	char line[256];
	char word[256];
	char change_word[256];
	char temp[256];
	char *p;
	int find_pos, i, j, m, c;
	
	printf("파일명을 입력하세요 : ");
	scanf("%s", fname);
	
	if((fp1 = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "%s 파일을 열지 못했습니다.", fname);
		return 0;
	}
	else
	{
		printf("%s 파일을 정상적으로 열었습니다.\n", fname);
	}
	
	
	// 원본 파일 뒤에 _capital.txt를 붙임 
	strncpy(fname1, fname, strlen(fname)-4);
	strcat(fname1, capi);
	
	
	if((fp2 = fopen(fname1, "w")) == NULL)
	{
		fprintf(stderr, "%s파일을 열지 못했습니다.", fname1);
		return 0;
	}
	else
	{
		printf("%s 파일을 정상적으로 열었습니다.\n", fname1);
	}
	
	printf("수정하고 싶은 단어를 입력하세요 : ");
	scanf("%s", word);
	printf("어떤 단어로 바꿀지 입력하세요 : ");
	scanf("%s", change_word); 
	
	while(fgets(line, 256, fp1) != NULL)
	{
		p = strstr(line, word);
		if (p)
		{
			strncpy(p, change_word, strlen(word));
			fputs(line, fp2);
		}
		else
		{
			fputs(line, fp2);
		}
	}
	
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;	
} 
