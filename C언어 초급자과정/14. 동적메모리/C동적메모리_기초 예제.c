#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *pi;
	pi = (int *)malloc(sizeof(int)); // malloc = �޸𸮸� �Ҵ��ض�.
	if(pi == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	 } 
	 *pi = 100;
	 printf("%d\n", *pi);
	 /* ���� �޸� ����� ���Ŀ��� ������ �ش� �޸𸮸� ��ȯ�մϴ�. */
	 
	 free(pi); 
		
	return 0;
}
