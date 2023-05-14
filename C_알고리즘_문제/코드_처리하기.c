#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int i, j = 0, mode = 0;
    int idx = strlen(code);
    char* answer = (char*)malloc(sizeof(char)*(idx+1));

    //printf("idx : %d\n", idx);
    //printf("%d, %s\n", strlen(answer), answer);
    
    for(i = 0; i < idx; i++){
        if(mode==0){
            if ((code[i] != '1') && (i%2==0)) answer[j++] = code[i];
            else if ((code[i]!='1') && (i%2==1)) continue;
            else mode = 1;
        }
        else{
            if((code[i]!='1') && (i%2==1)) answer[j++] = code[i];
            else if((code[i]!='1') && (i%2==0)) continue;
            else mode = 0;
        }
    }
    answer[j] = '\0'; // NULL
    if (strlen(answer)==0)
        strcpy(answer, "EMPTY");
    return answer;
}