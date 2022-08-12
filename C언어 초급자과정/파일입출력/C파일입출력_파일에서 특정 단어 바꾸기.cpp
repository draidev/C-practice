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
	
	printf("���ϸ��� �Է��ϼ��� : ");
	scanf("%s", fname);
	
	if((fp1 = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "%s ������ ���� ���߽��ϴ�.", fname);
		return 0;
	}
	else
	{
		printf("%s ������ ���������� �������ϴ�.\n", fname);
	}
	
	
	// ���� ���� �ڿ� _capital.txt�� ���� 
	strncpy(fname1, fname, strlen(fname)-4);
	strcat(fname1, capi);
	
	
	if((fp2 = fopen(fname1, "w")) == NULL)
	{
		fprintf(stderr, "%s������ ���� ���߽��ϴ�.", fname1);
		return 0;
	}
	else
	{
		printf("%s ������ ���������� �������ϴ�.\n", fname1);
	}
	
	printf("�����ϰ� ���� �ܾ �Է��ϼ��� : ");
	scanf("%s", word);
	printf("� �ܾ�� �ٲ��� �Է��ϼ��� : ");
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
