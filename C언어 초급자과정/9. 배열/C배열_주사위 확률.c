#include <stdio.h>

int swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int x = 10, y= 20;
	swap(&x, &y);
	
	printf("%d, %d", x, y);
	
	return 0; 
} 
