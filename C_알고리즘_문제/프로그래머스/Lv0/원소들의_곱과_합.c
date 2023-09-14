#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int i_mul, i_sum;
    i_mul = num_list[0];
    i_sum = num_list[0];

    for (int i = 1; i , i < num_list_len; i++) {
        i_mul *= num_list[i];
        i_sum += num_list[i];
    }

    i_sum = i_sum * i_sum;
    printf("%d\n", i_mul);
    answer = (i_mul < i_sum) ? 1 : 0;
    
    return answer;
}