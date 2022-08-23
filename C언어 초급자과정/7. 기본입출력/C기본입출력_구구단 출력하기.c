#include <stdio.h>
#define N 9

int main()
{
	int i, j;
	int x, n = 2, m = 1;
	int line;
	
	printf("구구단을 한 줄에 몇개씩 출력 할까요?");
	scanf("%d", &x); 
	
	while(i < 10)
	{
		for(j = 1 ; j <= 9 ; j++) // 구구단 뒷자리 1~9 
		{
				for(line = 0, i = n ; line < x ; line++, i++)
				{
					if (i>9) // i가 9보다 크면 출력하지 않고 넘어감 
					{
						continue;
					}	
					printf("%d x %d = %d   ", i, j, i*j);
				}
				printf("\n");
		}
		printf("\n");
		n = i;  // 다음에 출력할 구구단수를 저장 
	}

	return 0;
}

