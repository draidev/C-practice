
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char input[100];
	char fname[100];
	char temp[100];
	FILE *fp;
	int i = 0;
	char c;
		
	printf("파일 이름을 입력 하세요: ");
	scanf("%s", fname);
	
	if(fp = fopen(fname, "r") == NULL)
	{
		fprintf(stderr, "파일 %s를 열 수 없습니다.\n", fname);
		return 0;
	}
	
	printf("대문자로 변경하고자 하는 문자열을 입력 하세요: ");
	scanf("%s", input);
	
	while((c = fgetc(fp)) != EOF)
	{
		if (c == input[i])
		{
			temp[i] = c;
			i++;
			if (strlen(input) == strlen(temp))
			{
				for (i = 0; input[i] != '\0'; i++)
				{
					if (islower(input[i]))
					{
						input[i] = toupper(input[i]);
					}
				}
				i = 0;
			}
			
		}
		else
		{
			i = 0;
		}
	}
	
	
	for (i = 0; input[i] != '\0'; i++)
	{
		if (islower(input[i]))
		{
			input[i] = toupper(input[i]);
		}
	}
	
	
	printf("%s", input); 
	
	
	return 0;
}
