//# 2차원 배열의 크기를 입력 받은 후 포인터를 사용하여 관리 하는 프로그램을 작성 하세요. 
//# 배열에는 알파벳 소문자를 순차적으로 채워 넣고 전체 배열을 출력 하세요. 
//# 몇 번째 값을 출력 할지 입력 받은 후 해당 배열에 들어있는 값을 대문자로 출력 하세요. 

#include <stdio.h>


int main(void)
{
	int m, n, i, j, search;
	char k = 'a';
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d %d", &m,&n);
	int arr[m][n] ;
	int *ptr = arr;
	
	/* 배열에 알파벳 대입  */
//	for(i = 0; i < m; i++)
//	{
//		for(j = 0; j < n; j++)
//			arr[i][j] = k++;
//	}
	
	/* 배열에 알파벳 대입 */
	for(i = 0; i < m*n; i++)
	{
		*(ptr + i) = k++; 
	}

/* 배열과 포인터 주소 비교 */	
//	for(i = 0; i < m*n; i++)
//		printf("%d \n", ptr+i);
//	
//	printf("\n");
//	for(i = 0; i < m; i++)
//	{
//		for(j = 0; j < n; j++)
//			printf("%d \n", &arr[i][j]);
//	}
//	
	printf("생성된 배열은 아래와 같습니다.\n");
	for(i = 0; i < m*n; i++)
	{
		if (i != 0 && i % n == 0)
			printf("\n");
		printf("%c ", *(ptr + i));
	}
	
	printf("\n");
	printf("몇 번째 값을 알려드릴까요?");
	scanf("%d", &search);
	printf("%c", *(ptr + search - 1));	
	
	return 0;
}
