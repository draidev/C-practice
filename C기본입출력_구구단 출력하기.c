#include <stdio.h>
#define N 9

int main()
{
	int i, j;
	int x, n = 2, m = 1;
	int line;
	
	printf("�������� �� �ٿ� ��� ��� �ұ��?");
	scanf("%d", &x); 
	
	while(i < 9)
	{
		for(j = 1 ; j <= 9 ; j++) // ������ �޺κ� 1~9 
		{
				for(line = 0, i = n ; line < x ; line++, i++)
				{
					if (i>9) // 9�� �ѱ�� ��������ʰ� �Ѿ 
					{
						continue;
					}	
					printf("%d x %d = %d   ", i, j, i*j);
				}
				printf("\n");
		}
		printf("\n");
		n = i;  // ������ �պκ��� �����ؼ� ���� �ٲ�ڿ� ���� ���� ����ϵ��� ��
	}

	return 0;
}
