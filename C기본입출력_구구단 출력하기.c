#include <stdio.h>
#define N 9

int main()
{
	int i, j;
	int x, n = 2, m = 1;
	int line;
	
	printf("구구단을 한 줄에 몇개씩 출력 할까요?");
	scanf("%d", &x); 
	
	while(i < 9)
	{
		for(j = 1 ; j <= 9 ; j++) // 곱셈의 뒷부분 1~9 
		{
				for(line = 0, i = n ; line < x ; line++, i++)
				{
					if (i>9) // 9를 넘기면 출력하지않고 넘어감 
					{
						continue;
					}	
					printf("%d x %d = %d   ", i, j, i*j);
				}
				printf("\n");
		}
		printf("\n");
		n = i;  // 곱셈의 앞부분을 저장해서 줄이 바뀐뒤에 다음 단을 출력하도록 함
	}

	return 0;
}
