#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int i;
    
    if ( n % 2 == 1 ) {
        for (i =0; i <= n; i++) {
            if ( i % 2 == 1) answer += i;
        }    
    }
    else { 
        for (i = 0; i <= n; i++){
            if ( i % 2 == 0 ) answer += i*i;
        }
    }
    
    return answer;
}