//# 2���� �迭�� ũ�⸦ �Է� ���� �� �����͸� ����Ͽ� ���� �ϴ� ���α׷��� �ۼ� �ϼ���. 
//# �迭���� ���ĺ� �ҹ��ڸ� ���������� ä�� �ְ� ��ü �迭�� ��� �ϼ���. 
//# �� ��° ���� ��� ���� �Է� ���� �� �ش� �迭�� ����ִ� ���� �빮�ڷ� ��� �ϼ���. 

#include <stdio.h>


int main(void)
{
	int m, n, i, j, search;
	char k = 'a';
	printf("�迭�� ũ�⸦ �Է��ϼ��� : ");
	scanf("%d %d", &m,&n);
	int arr[m][n] ;
	int *ptr = arr;
	
	/* �迭�� ���ĺ� ����  */
//	for(i = 0; i < m; i++)
//	{
//		for(j = 0; j < n; j++)
//			arr[i][j] = k++;
//	}
	
	/* �迭�� ���ĺ� ���� */
	for(i = 0; i < m*n; i++)
	{
		*(ptr + i) = k++; 
	}

/* �迭�� ������ �ּ� �� */	
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
	printf("������ �迭�� �Ʒ��� �����ϴ�.\n");
	for(i = 0; i < m*n; i++)
	{
		if (i != 0 && i % n == 0)
			printf("\n");
		printf("%c ", *(ptr + i));
	}
	
	printf("\n");
	printf("�� ��° ���� �˷��帱���?");
	scanf("%d", &search);
	printf("%c", *(ptr + search - 1));	
	
	return 0;
}
