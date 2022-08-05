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
		for(j = 1 ; j <= 9 ; j++)
		{
				for(line = 0, i = n ; line < x ; line++, i++)
				{
					if (i>9)
						continue;
					printf("%d x %d = %d   ", i, j, i*j);
				}
				printf("\n");
		}
		printf("\n");
		n = i;
	}

	
//	for(i = 2 ; i <= N ; i++)
//	{
//		for(j = 1 ; j <= N ; j++)
//			{
//				printf("%d x %d = %d\n", i, j, i*j);
//			} 
//	}
		 
	return 0;
}
