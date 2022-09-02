#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("body.png", "r");
	
	printf("%s", fp);
	
	fclose(fp);
		
	return 0;
}
