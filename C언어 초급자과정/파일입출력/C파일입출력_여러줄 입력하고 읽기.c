#include <stdio.h>

int main()
{
	FILE *fp1;
	char fname[20];
	char input[256];
	char line[256];
	int i;
		
	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);
	
	if((fp = fopen(fname, "w"))==NULL)
	{
		fprintf(stderr, "%s 파일을 여는데 실패했습니다.", fname);
		return 0;
	}
	else
	{
		printf("파일이 정상적으로 열렸습니다.\n");
	}
	
	
	for (i = 0; i < 2; i++)
	{
		printf("문자를 입력하세요 : ");
		getchar();
		scanf("%[^\n]s", input);
		fprintf(fp, "%s\n", input);
	}
	
	fclose(fp);
	
	/* 파일 내용 읽기 */
	if((fp=fopen(fname, "r"))==NULL)
	{
		fprintf(stderr, "%s 파일을 여는데 실패했습니다.", fname);
		return 0;
	}
	else
	{
		printf("파일이 정상적으로 열렸습니다.\n");
	}
	
	while(fgets(line, 256, fp) != NULL)
	{
		printf("%s", line);
	}
	
	fclose(fp);
	
	return 0;
}
