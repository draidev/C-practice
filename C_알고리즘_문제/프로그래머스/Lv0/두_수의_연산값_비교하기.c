#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    char buffer[16] = {0, };
    int temp;

    snprintf(buffer, sizeof(buffer), "%d%d", a, b);
    temp = atoi(buffer);
    
    if (temp > 2*a*b) answer = temp;
    else answer = 2*a*b;
    
    return answer;
}