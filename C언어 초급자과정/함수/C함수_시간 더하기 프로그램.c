#include <stdio.h>

//특정한 금액을 받아서 가장 적은 거스름 화폐의 개수를 구하는 함수
int smallest(int number)
{
	int count = 0;
	while(number >= 50000)
	{
		number -= 50000;
		count++;	
	}	
	while(number >= 10000)
	{
		number -= 10000;
		count++;
	}
	while(number >= 5000)
	{
		number -= 5000;
		count++;
	}
	while(number >= 1000)
	{
		number -= 1000;
		count++;
	}
	while(number >= 500)
	{
		number -= 500;
		count++;
	} 
	
	return count;
}

int main()
{
	int money;
	int count;
	
	printf("금액을 입력하세요 : ");
	scanf("%d", &money);
	
	count = smallest(money);
	printf("최소로 줄 수 있는 화폐의 개수 : %d", count);

		
	return 0;
}
