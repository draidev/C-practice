#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, x, y;
	int **pptr = (int**)malloc(sizeof(int*) * 8);
	for(i = 0; i < 6; i++)
	{
		*(pptr + i) = (int*)malloc(sizeof(int) * 6);
	}
	
	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 6; x++)
		{
			*(*(pptr + y) + x) = 6 * y + x;
		}
	}
	
	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 6; x++)
		{
			printf("%3d", *(*(pptr + y) + x));
		}
		printf("\n");
	}
	
	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 6; x++)
		{
			free(*(*(pptr + y) + x));
		}
	}
	
	return 0;
}
