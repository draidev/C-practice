#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int i, j;
    char temp[16] = {0,};
    
    /*
    char** answer = (char**)malloc(sizeof(char*) * players_len);
    for (i = 0; i < players_len; i++){
        *(answer + i) = (char*)malloc(sizeof(char) * 16);
    }
    */
    for (i = 0; i < callings_len; i++)
    {
        for (j = 0; j < players_len; j++){
            strcpy(temp,players[j]);
            if (strcmp(players[j], callings[i]) == 0){
                //memset(players[j], 0, sizeof(char)*10);
                strcpy(players[j], players[j-1]);
                //memset(players[j-1], 0, sizeof(char)*10);
                strcpy(players[j-1], temp);
            }
            //memset(temp, 0, sizeof(char)*16);
        }
    }
    
    return players;
}