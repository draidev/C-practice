//# 입력받은 수식을 계산하는 계산기를 만들어 보세요.
//# 수식은 사칙연산(+,-,*,/)만 허용되며 각 사칙연산은 함수로 작성 해야 합니다. 
//# 잘못된 수식을 입력한 경우 오류를 출력 해야 합니다. 
//
//# 출력 예)
//# 수식을 입력 하세요: 2 * 5
//# 2 * 5 = 10

#include <stdio.h>

// 덧셈 
float sum(float num1, float num2)
{
	return num1 + num2;
}

// 뺼셈 
float substract(float num1, float num2)
{
	return num1 - num2;
}
 
// 곱셈 
float multiply(float num1, float num2)
{
	return num1 * num2;
}

// 나눗 
float divide(float num1, float num2)
{
	return num1 / num2;
}


int main()
{
	float num1, num2;
	char o; 
	
	printf("수식을 입력하세요 : ");
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
		printf("잘못된 수식을 입력했습니다.\n");
	}
		
	return 0;
}
