#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

int main(void)
{
	int *imem, *i_arr[10];
	char *cmem, *c_arr[10];
	double *dmem;
	int sel, i, i_n, c_n, all_mem=0, use_mem=0, free_mem=0, i_flag=0, c_flag=0;
	
	printf("할당할 메모리 자료형을 선택하세요.\n");
	printf("1. int\n");
	printf("2. char\n");
	scanf("%d", &sel);
	
	while(1)
	{
		if(sel == 0)
		{
			printf("**********종료**********\n") ;
			break;
		}
		
		switch(sel)
		{
			case 1:
				printf("정수형 변수의 크기를 입력해주세요. ");
				scanf("%d", &i_n);
				i_arr[i_flag] = (int*)malloc(sizeof(int) * i_n);
				all_mem += sizeof(*i_arr[i_flag])*i_n;
				use_mem += sizeof(*i_arr[i_flag])*i_n;
				i_flag++;
				
				printf("\n====================================================================\n");
				printf("total allocated memory : %dB, used memory : %dB, freed memory : %dB\n", all_mem, use_mem, free_mem);
				printf("====================================================================\n");
				break;
				
			case 2:
				printf("문자형 변수의 크기를 입력해주세요. ");
				scanf("%d", &c_n);
				c_arr[c_flag] = (char*)malloc(sizeof(char) * c_n);
				cmem = (char*)malloc(sizeof(char) * c_n);
//				c_arr[c_flag] = (char*)calloc(n, sizeof(char));
				all_mem += sizeof(*c_arr[c_flag])*c_n;
				use_mem += sizeof(*c_arr[c_flag])*c_n;
				c_flag++;
				
				printf("\n====================================================================\n");
				printf("total allocated memory : %dB, used memory : %dB, freed memory : %dB\n", all_mem, use_mem, free_mem);
				printf("====================================================================\n");
				break;
				
			case 3:
				if (i_flag <1)
				{
					printf("할당된 메모리가 없습니다.\n\n");
					break;
				}
				i_flag--;
				use_mem -= sizeof(*i_arr[i_flag])*i_n;
				free_mem += sizeof(*i_arr[i_flag])*i_n;
				free(i_arr[i_flag]);
				
				printf("\n====================================================================\n");
				printf("total allocated memory : %dB, used memory : %dB, freed memory : %dB\n", all_mem, use_mem, free_mem);
				printf("====================================================================\n");
				break;
			
			case 4:
				if (c_flag <1)
				{
					printf("할당된 메모리가 없습니다.\n\n");
					break;
				}
				
				c_flag--;
				use_mem -= sizeof(*c_arr[c_flag])*c_n;
				free_mem += sizeof(*c_arr[c_flag])*c_n;
				free(c_arr[c_flag]);
				
				printf("\n====================================================================\n");
				printf("total allocated memory : %dB, used memory : %dB, freed memory : %dB\n", all_mem, use_mem, free_mem);
				printf("====================================================================\n");
				break;
			
			default:
				printf("잘못 입력하였습니다.\n");
		}
		
		printf("\n어떤 작업을 하시겠습니까?\n");
		printf("1. int메모리 할당\n");
		printf("2. char메모리 할당\n");
	 	printf("3. int메모리 해제\n");
	 	printf("4. char메모리 해제\n");
		printf("0. 종료\n");
		scanf("%d", &sel);
	}
	
	free(imem);
	free(cmem);
	
	return 0;
}
