#include <stdio.h>


int main(void)
{
	int arr[3] = { 5, 10, 15 };
	int i;
	int *ptr = arr;
	
	for(i = 0; i < 3; i++)
	{
		printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);	
	} 
	for(i = 0; i < 3; i++)
	{
		printf("������ ptr[%d]�� ��: %d\n", i, ptr[i]);
	}
	
	for(i = 0; i < 3; i++)
	{
		printf("�迭 arr[%d]�� �� : %d\n", i, *(arr + i));	
	} 
	for(i = 0; i < 3; i++)
	{
		printf("������ ptr[%d]�� ��: %d\n", i, *(ptr + i));
	}
	
	// *(arr + i) == arr[i] �Ȱ��� ǥ��
	// arr == arr �迭�� ù���� ���� �ּҿ� ���� == &arr[0] 
	printf("arr ��ü�� �� : %d\n", arr);
	printf("arr[0]�� �ּ� : %d\n", &arr[0]);
	
	printf("arr ��ü�� ���� ������ �ּ��� ���� ��: %d\n", *arr);
	printf("arr[0]�� ��ü�� �� : %d", arr[0]);
	
	return 0;
}
