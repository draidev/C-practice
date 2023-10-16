#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sqr_func(int num, int count);
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int i;
    int even_cnt=0, odd_cnt=0;
    int even_num=0, odd_num=0;
    
    for (i = 0; i < num_list_len; i++) {
        if (num_list[i] % 2 == 0)
            even_cnt++;
        else
            odd_cnt++;
    }
    
    printf("%d %d\n", even_cnt, odd_cnt);
    
    for (i = 0; i < num_list_len; i++) {
        if (num_list[i] % 2 == 0) {
            printf("sqr : %d\n", sqr_func(10, even_cnt));
            even_num += num_list[i] * sqr_func(10, even_cnt);
            printf("%d\n", even_num);
            even_cnt--;
        }
        else {
            odd_num += num_list[i] * sqr_func(10, odd_cnt);
            odd_cnt--;
        }
    }
    
    answer = even_num + odd_num;
    
    return answer;
}

int sqr_func(int num, int count){
    int result=1;
    if (count > 1) {
        count--;
        result = sqr_func(num, count);
    }
    else return 1;
    
    return result * num;
}