#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    char temp[256], *p;
    int find_pos;
    
	if ((fp1 = fopen("test.txt", "r")) != NULL)
	{
		printf("������ ���������� ���Ƚ��ϴ�.\n");
		while (fgets(temp, 256, fp1) != NULL){
			p = strstr(temp, );
			
			if (p != NULL)
			{
				find_pos = strlen(temp) - (p - temp) + 1;
				
				fseek(fp1, (-1)*find_pos, SEEK_CUR);
				
				fwrite("h", sizeof(char), 1, fp1);
				
				fseek(fp1, find_pos - 4, SEEK_CUR); 
			} 
		}
		fclose(p_file);
	}
	else printf("������ ������ �ʾҽ��ϴ�.\n");
	
	return 0;
}
