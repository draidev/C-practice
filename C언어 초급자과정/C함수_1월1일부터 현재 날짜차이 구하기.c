//# �Է¹��� ������ ����ϴ� ���⸦ ����� ������.
//# ������ ��Ģ����(+,-,*,/)�� ���Ǹ� �� ��Ģ������ �Լ��� �ۼ� �ؾ� �մϴ�. 
//# �߸��� ������ �Է��� ��� ������ ��� �ؾ� �մϴ�. 
//
//# ��� ��)
//# ������ �Է� �ϼ���: 2 * 5
//# 2 * 5 = 10

#include <stdio.h>

// ���� 
float sum(float num1, float num2)
{
	return num1 + num2;
}

// �E�� 
float substract(float num1, float num2)
{
	return num1 - num2;
}
 
// ���� 
float multiply(float num1, float num2)
{
	return num1 * num2;
}

// ���� 
float divide(float num1, float num2)
{
	return num1 / num2;
}


int main()
{
	float num1, num2;
	char o; 
	
	printf("������ �Է��ϼ��� : ");
	scanf("%f %c %f", &num1, &o, &num2);

	if(o == '+')
	{
		printf("%.1f\n", sum(num1, num2));
	}
	else if(o == '-')
	{
		printf("%.1f\n", substract(num1, num2));
	}
	else if(o == '*')
	{
		printf("%.1f\n", multiply(num1, num2));
	}
	else if(o == '/')
	{
		printf("%.1f\n", divide(num1, num2));
	}
	else
	{
		printf("�߸��� ������ �Է��߽��ϴ�.\n");
	}
		
	return 0;
}
