//# ���ڿ��� �Է� �޾� �м� �� ����� ��� �ϼ���. 
//# ��ҹ��ڸ� �������� ���� �Է¹��� ���ڿ��� �� ���̿� 
//# ���� ���� ���� ���ڿ� ���� ���� ���� ���ڸ� Ƚ���� �Բ� ��� �ϼ���. 

#include<stdio.h>
#include<string.h>

int main(void)
{
	int i, j, len; 
	char ch_max, ch_min, ch_temp;
	char input[100] = "";
	char ch_arr[50] = "";
	int int_arr[50] = { 0, };
	
	printf("���ڿ��� �Է� �ϼ��� : ");
	scanf("%s", input);
	
	len = strlen(input);
	
	for(i = 0; input[i]; i++)
	{
		ch_temp = input[i];

		for (j = 0; ch_arr[j]; j++)
		{
			if (ch_temp == ch_arr[j])
			{
				int_arr[j]++;
				break;
			}
		}
		
		printf("%c\n", input[i]);		
	}	
	
	for(i = 0; int_arr[i] != 0; i++)
	{
		printf("���� %d\n", int_arr[i]);
	}

	
	
//	printf("�� ����: %d, �ִ� ���: %c (%d), �ּ� ���: %c (%d)", length, ch_max, int_max, ch_min, int_min);
	
	return 0;
} 
