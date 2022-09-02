#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b64_encoding.h"

int main()
{
	FILE *fp =NULL;
	FILE *image = NULL;
	int size, src_size, src_loc, src_end_loc, check;
	char *html_str, *src_str, *src_end;
	
	fp = fopen("body.html","r+");
	image = fopen("body.png", "r");
	
	//image
	printf("image : %s\n\n", image);
	
	//fp 
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("size : %d\n", size);
	fseek(fp, 0, SEEK_SET);
	
	html_str = (char*)malloc(sizeof(char) * size);
	fgets(html_str, size + 1, fp);
	src_str = strstr(html_str, "src");
	printf("html_src : %s\n\n", html_str);
	printf("src_str : %s\n\n", src_str+4);
	printf("htmlsrc : %p\nsrc_str : %p\n\n", html_str, src_str);
	src_loc = src_str - html_str;
	printf("src_loc : %d\n\n", src_loc);
	
	fseek(fp, 0, SEEK_SET);
	fseek(fp, src_loc, SEEK_CUR);
	check = ftell(fp);
	printf("SRC CHECK : %d\n\n", check);
	
	src_end = strstr(src_str, "\">");
	printf("src_end : %s\n\n", src_end);
	printf("src_end_p : %p\n\n", src_end);
	src_end_loc = src_end - html_str;
	printf("src_end_loc : %d\n\n", src_end_loc);
	
	
	//free memory
	free(html_str);
	fclose(fp);
	fclose(image);
	
	return 0;
}
