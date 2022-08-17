#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char input[100];
	char alpha[27];
	char maxc, minc;
	int max_min[27] = { 0, };
	int max = 0, min = 0;
	int i, j;
	
	for(i = 0; i < 26; i++)
	{
		alpha[i] = 97 + i;
	}
	
	printf("문자열을 입력하세요 : ");
	scanf("%s", input);
	
	for(i = 0; i < strlen(input); i++)
	{
		for(j = 0; j < 26; j++)
		{
			if (tolower(input[i]) == alpha[j])
			{
				max_min[j]++;
				break;		
			}
		}
	}
	
	min = max_min[0]; 
	for(i = 0; i < strlen(input); i++)
	{
		if(max < max_min[i])
		{
			maxc = alpha[i];
			max = max_min[i];
		}
		
		if(max_min[i] != 0 && min > max_min[i])
		{
			minc = alpha[i];
			min = max_min[i];
		}
	}
	
	printf("총 길이: %d, 최다 사용: %c (%d), 최소 사용: %c (%d)", strlen(input), maxc, max, minc, min);
			
	return 0;
}
