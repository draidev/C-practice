#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b64_encoding.h"

#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <sched.h>
#include <dirent.h>
// #include <iconv.h>
#include <wchar.h>

char * sd_string_alloc_base64_encode(const unsigned char *src, size_t len, size_t *out_len);

int main()
{
	FILE *fp =NULL;
	FILE *image_fp = NULL;
	FILE *copy_fp = NULL;
	long lSize, size;
	char *i_buffer, *h_buffer;
	char base[50000] = "data:image/png;base64,";
	char *temp, *next_src_temp;
	int find_src;
	size_t result;
	char *html_ptr, *src_ptr;
	
 	// 파일 오픈 
	image_fp = fopen("body.png","rb");
	fp = fopen("body.html","r+");
	copy_fp = fopen("copy_body.html","w");
	
	if (image_fp == NULL) {
		fputs("File error", stderr);
		exit(1);
	}
	
	// png 크기 구하기 
	fseek(image_fp, 0, SEEK_END);
	lSize = ftell(image_fp);
	rewind(image_fp);
	
	i_buffer = (char*)malloc(sizeof(char) * lSize);
	if (i_buffer == NULL) {
		fputs("Memory error", stderr);
		exit(2);
	}
	
	result = fread(i_buffer, 1, lSize, image_fp);
	
	if (result != lSize) {
		fputs("Reading error", stderr);
		exit(3);
	}
	
//====================================================================
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	
	h_buffer = (char*)malloc(sizeof(char) * size);
	//	fread(h_buffer, sizeof(char), size, fp);  <- 에러 
	fgets(h_buffer ,size + 1, fp);
	printf("fp : %d\n", ftell(fp));
	rewind(fp);
	
	fwrite(h_buffer, sizeof(char), size + 1, copy_fp);

	// src 위치로 파일포인터 이동
	src_ptr = strstr(h_buffer, "src=");
	find_src = src_ptr - h_buffer + 5;
	
	fseek(fp, find_src, SEEK_CUR);
	// copy_fp 포인터 처음으로 이동시킨후 src="으로 다시 이동 
	rewind(copy_fp);
	fseek(copy_fp, find_src, SEEK_CUR);
	
	fgets(h_buffer, size, fp);
	next_src_temp = strstr(h_buffer, "\">");  // src 뒷부분 저장 
	rewind(fp);
	fseek(fp, find_src, SEEK_CUR);// src=" 위치로 이동 
	
	temp = sd_string_alloc_base64_encode(i_buffer, result, 0);
	strcat(base, temp);
	strcat(base, next_src_temp);
	
	int num;
	num = fwrite(base, sizeof(char), strlen(base), copy_fp);
	fgets(h_buffer, 50000, fp);
	printf("copyfp : %s\n", h_buffer);
	printf("num : %d\n", num);

	fclose(image_fp);
	fclose(fp);
	free(i_buffer);
	free(h_buffer);

	return 0;
}


static const unsigned char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char * sd_string_alloc_base64_encode(const unsigned char *src, size_t len, size_t *out_len)
{
    unsigned char *out, *pos;
    const unsigned char *end, *in;
    size_t olen;
    int line_len;

    olen = len * 4 / 3 + 4; /* 3-byte blocks to 4-byte */
    olen += olen / 72; /* line feeds */
    olen++; /* nul termination */
    if (olen < len) return NULL; /* integer overflow */
    out = calloc(1, olen);
    if (out == NULL) return NULL;

    end = src + len;
    in = src;
    pos = out;
    line_len = 0;
    while (end - in >= 3) {
        *pos++ = base64_table[in[0] >> 2];
        *pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
        *pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
        *pos++ = base64_table[in[2] & 0x3f];
        in += 3;
        line_len += 4;
        if (line_len >= 72) {
            *pos++ = '\n';
            line_len = 0;
        }
    }

    if (end - in) {
        *pos++ = base64_table[in[0] >> 2];
        if (end - in == 1) {
            *pos++ = base64_table[(in[0] & 0x03) << 4];
            *pos++ = '=';
        } else {
            *pos++ = base64_table[((in[0] & 0x03) << 4) |
                (in[1] >> 4)];
            *pos++ = base64_table[(in[1] & 0x0f) << 2];
        }
        *pos++ = '=';
        line_len += 4;
    }

    if (line_len)
        *pos++ = '\n';

    *pos = '\0';
    if (out_len) *out_len = pos - out;
    return (char *)out;
}

