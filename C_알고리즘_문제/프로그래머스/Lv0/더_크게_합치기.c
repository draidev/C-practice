#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    char ab[11] = {0,};
    char ba[11] = {0,};
    int ab_int;
    int ba_int;
    
    snprintf(ab, sizeof(char)*11, "%d%d", a, b);
    snprintf(ba, sizeof(char)*11, "%d%d", b, a);
    
    ab_int = atoi(ab);
    ba_int = atoi(ba);
    
    if (ab_int >= ba_int) answer = ab_int;
    else answer = ba_int;
    
    return answer;
}