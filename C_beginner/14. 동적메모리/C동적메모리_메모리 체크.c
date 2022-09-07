#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

int main(void)
{
	int *imem, *i_arr[10];
	char *cmem, *c_arr[10];
	double *dmem;
	int sel, i, i_n, c_n, all_mem=0, use_mem=0, free_mem=0, i_flag=0, c_flag=0;
	
	printf("�Ҵ��� �޸� �ڷ����� �����ϼ���.\n");
	printf("1. int\n");
	printf("2. char\n");
	scanf("%d", &sel);
	
	while(1)
	{
		if(sel == 0)
		{
			printf("**********����**********\n") ;
			break;
		}
		
		switch(sel)
		{
			case 1:
				printf("������ ������ ũ�⸦ �Է����ּ���. ");
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
				printf("������ ������ ũ�⸦ �Է����ּ���. ");
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
					printf("�Ҵ�� �޸𸮰� �����ϴ�.\n\n");
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
					printf("�Ҵ�� �޸𸮰� �����ϴ�.\n\n");
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
				printf("�߸� �Է��Ͽ����ϴ�.\n");
		}
		
		printf("\n� �۾��� �Ͻðڽ��ϱ�?\n");
		printf("1. int�޸� �Ҵ�\n");
		printf("2. char�޸� �Ҵ�\n");
	 	printf("3. int�޸� ����\n");
	 	printf("4. char�޸� ����\n");
		printf("0. ����\n");
		scanf("%d", &sel);
	}
	
	free(imem);
	free(cmem);
	
	return 0;
}
