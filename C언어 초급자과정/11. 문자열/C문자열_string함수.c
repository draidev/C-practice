//# 문자열을 입력 받아 분석 후 결과를 출력 하세요. 
//# 대소문자를 구분하지 말고 입력받은 문자열의 총 길이와 
//# 가장 많이 나온 문자와 가장 적게 나온 문자를 횟수와 함께 출력 하세요. 

#include<stdio.h>
#include<string.h>

int main(void)
{
	int i, j, len; 
	char ch_max, ch_min, ch_temp;
	char input[100] = "";
	char ch_arr[50] = "";
	int int_arr[50] = { 0, };
	
	printf("문자열을 입력 하세요 : ");
	scanf("%s", input);
	
	len = strlen(input);
	
	for(i = 0; input[i]; i++)
	{
		ch_temp = input[i];

		for (j = 0; ch_arr[j]; j++)
		{
			if (ch_temp == ch_arr[j])
			{
				int_arr[j]++;
				break;
			}
		}
		
		printf("%c\n", input[i]);		
	}	
	
	for(i = 0; int_arr[i] != 0; i++)
	{
		printf("개수 %d\n", int_arr[i]);
	}

	
	
//	printf("총 길이: %d, 최다 사용: %c (%d), 최소 사용: %c (%d)", length, ch_max, int_max, ch_min, int_min);
	
	return 0;
} 
