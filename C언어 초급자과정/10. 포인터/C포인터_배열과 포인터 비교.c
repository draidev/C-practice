#include <stdio.h>


int main(void)
{
	int arr[3] = { 5, 10, 15 };
	int i;
	int *ptr = arr;
	
	for(i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);	
	} 
	for(i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]);
	}
	
	for(i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i));	
	} 
	for(i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값: %d\n", i, *(ptr + i));
	}
	
	// *(arr + i) == arr[i] 똑같은 표현
	// arr == arr 배열의 첫번쨰 값의 주소와 동일 == &arr[0] 
	printf("arr 자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);
	
	printf("arr 자체의 값이 가지는 주소의 실제 값: %d\n", *arr);
	printf("arr[0]이 자체의 값 : %d", arr[0]);
	
	return 0;
}
