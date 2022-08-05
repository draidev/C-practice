#include <stdio.h>
#define N 9

int main()
{
	int i, j, m;
	int flag = 0; // 알파벳이 다시 줄어들기 시작하면 줄어드는 알파벳을 표현하기 위해 초기화 
	char x = 'A';
	
	for(i = 0 ; i < N ; i++)
	{	
		if (i <= N/2)
		{
			for(j = N/2 ; j > i ; j--)
			{
				printf(" ");
			}

			printf("%c", x+i);
			
			for(j = 0 ; j < i ; j++)
			{
				printf(" ");
			}
			
			for(j = 1; j < i ; j++)
			{
				printf(" ");
			}
			
			if (i != 0)
				printf("%c", x+i);
				
			printf("\n");
		}
		
		else
		{
			flag += 1; 
			for(m = 0 ; m < i-j ; m++)
			{
				printf(" ");
			}
			
			printf("%c",x + i - (2*flag));
			
			for(m = N - 1 ; m > i ; m-- )
			{
				printf(" ");
			}
			
			for(m = N - 2 ; m > i ; m--)
			{
				printf(" ");
			}
			
			if(i < N - 1)
				printf("%c", x + i - (2*flag));
			
			printf("\n");
		}
	}
	

	return 0;
}
