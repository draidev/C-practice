#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    char buffer[16] = {0, };
    int temp;
    //snprintf(buffer, sizeof(buffer), "%c%c\0", a, b);  
    //printf("%s\n", buffer);
    if (a < 10)
        printf("%c\n", a+'0');
    else if (a / 10 < 10)
        snprintf(buffer, sizeof(buffer), "%c", a/10);
    else {
        temp = a / 10;
        while (temp < 10) {
            temp = temp / 10;
        }
        snprintf(buffer, sizeof(buffer), "%c", a/10);
    }
    
    printf("%s\n", buffer);
    
    return answer;
}