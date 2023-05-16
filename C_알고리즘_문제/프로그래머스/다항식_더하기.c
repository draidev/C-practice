// https://school.programmers.co.kr/learn/courses/30/lessons/120863#
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rm_space(char* str);
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial) {
    char* token;
    char chr_temp[16] = {0};
    char const_temp[16];
    int x_cnt = 0;
    int const_cnt = 0;
    int j = 0;
    
    token = strtok(polynomial, "+");
    while(token != NULL) {
        //printf("token : %s\n", token);
        if (strchr(token, 'x')) {
            rm_space(token);
            if (strlen(token) > 1) {
                for(int i = 0; i < strlen(token); i++)
                {  
                    if(token[i] != 'x') {
                        chr_temp[j] = token[i];
                        //printf("chr : %s\n", chr_temp);
                        j++;
                    }
                }
                x_cnt += atoi(chr_temp);
                //printf("x_cnt : %d\n", x_cnt);
                memset(chr_temp, 0, sizeof(chr_temp));
                j = 0;
            } 
            else x_cnt++;
        }
        else {
            const_cnt += atoi(token);
        }            
        token = strtok(NULL, "+");
    }
    //printf("x_cnt : %d const_cnt : %d \n", x_cnt, const_cnt);
    
    char* answer = (char*)malloc(sizeof(char) * 500);
    /*
    if (x_cnt == 0) {
        if (const_cnt == 0)	sprintf(answer, "0");
        else				sprintf(answer, "%d", const_cnt);
    }
    */
    if (x_cnt == 0)	sprintf(answer, "%d", const_cnt);
    else if (const_cnt == 0) {
        if(x_cnt == 1)	sprintf(answer, "x");
        else			sprintf(answer, "%dx", x_cnt);
    }
    else {
        if (x_cnt == 1)	sprintf(answer, "x + %d", const_cnt);
		else			sprintf(answer, "%dx + %d", x_cnt, const_cnt);
    }
    
    printf("%s\n", answer);
    return answer;
}

void rm_space(char *str) {
    char *src = str, *dst = str;
    while(*src) {
        if(!isspace(*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}