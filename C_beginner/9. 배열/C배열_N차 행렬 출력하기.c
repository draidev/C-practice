//# N차 행렬을 출력해 보세요  
//# 입력 받은 숫자 만큼의 행렬을 출력 하고, 행렬 안에는 숫자를 1부터 채워줍니다. 
//# 숫자는 좌측상단에서 시작하여 반시계 방향으로 돌아가며 순차적으로 채워줍니다. 

#include <stdio.h>

int main()
{
	int n, max, i, j, x = -1, y = 0, z = 1, num = 1;
	
	printf("출력할 행렬의 크기를 입력 하세요: ");
	scanf("%d", &n);
	
	int arr[n][n];  // 행렬의 크기만큼 배열크기 초기화 
	max = n;
	
	while(max > 0)
	{
		for(i = 0; i < max; i++)
		{
			x = x + z;
			arr[x][y] = num;
			num++;
		}
		max--;
		
		for(i = 0; i < max; i++)
		{
			y = y + z;
			arr[x][y] = num;
			num++;
		}
		z *= -1;
	}
	

	// 행렬 출력 
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%3d", arr[i][j]);		
		}		
		printf("\n");
	}	
}
