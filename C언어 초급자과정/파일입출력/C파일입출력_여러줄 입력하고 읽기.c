#include <stdio.h>

int main()
{
	FILE *fp1;
	char fname[20];
	char input[256];
	char line[256];
	int i;
		
	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);
	
	if((fp = fopen(fname, "w"))==NULL)
	{
		fprintf(stderr, "%s ������ ���µ� �����߽��ϴ�.", fname);
		return 0;
	}
	else
	{
		printf("������ ���������� ���Ƚ��ϴ�.\n");
	}
	
	
	for (i = 0; i < 2; i++)
	{
		printf("���ڸ� �Է��ϼ��� : ");
		getchar();
		scanf("%[^\n]s", input);
		fprintf(fp, "%s\n", input);
	}
	
	fclose(fp);
	
	/* ���� ���� �б� */
	if((fp=fopen(fname, "r"))==NULL)
	{
		fprintf(stderr, "%s ������ ���µ� �����߽��ϴ�.", fname);
		return 0;
	}
	else
	{
		printf("������ ���������� ���Ƚ��ϴ�.\n");
	}
	
	while(fgets(line, 256, fp) != NULL)
	{
		printf("%s", line);
	}
	
	fclose(fp);
	
	return 0;
}
