#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * privacies_len);
    int i, j, m, i_terms_num;
    char *dup_today, *to_year, *to_month, *to_day;
    int i_to_year, i_to_month, i_to_day;
    char *dup_priv, *priv_date, *priv_alpha;
    char *dup_terms, *terms_alpha, * terms_num;
    char *year_tok, *month_tok, *day_tok;
    int i_year, i_month, i_day;
    int temp_year, temp_month;
    int index = 0;
    
    dup_today = strdup(today);
    
    to_year = strtok(dup_today, ".");
    to_month = strtok(NULL, ".");
    to_day = strtok(NULL, ".");
    i_to_year = atoi(to_year);
    i_to_month = atoi(to_month);
    i_to_day = atoi(to_day);
    
    for (i = 0; i < privacies_len; i++) {
        dup_priv = strdup(privacies[i]);
        priv_date = strtok(dup_priv, " ");
        priv_alpha = strtok(NULL, " ");
        
        for (j = 0; j < terms_len; j++) {
            dup_terms = strdup(terms[j]);
            terms_alpha = strtok(dup_terms, " ");
            terms_num = strtok(NULL, " ");
            if (strcmp(priv_alpha, terms_alpha) == 0) {
                break;
            }
        }
        i_terms_num = atoi(terms_num);
    
        year_tok = strtok(priv_date,"."); 
        month_tok = strtok(NULL, ".");
        day_tok = strtok(NULL, ".");
        i_year = atoi(year_tok);
        i_month = atoi(month_tok);
        i_day = atoi(day_tok);
        
        temp_year = i_year;
        temp_month = i_terms_num + i_month; 
        
        while(temp_month > 12) {
            temp_year += 1;
            temp_month -= 12;
        }
        
        printf("#2 temp : %d %d\n", temp_year, temp_month);
        printf("#3 temp_month : %d,%d\n", temp_month, i_to_month);
        if (temp_year > i_to_year) continue;
    	else if (temp_year == i_to_year) {
            if (temp_month < i_to_month) { 
                answer[index++] = i + 1;
                continue;
            }
            else if (temp_month == i_to_month) { 
            	if (i_day <= i_to_day) {
                    answer[index++] = i + 1;
                    continue;
                }
            }
            else continue;
        }
        else {
            answer[index++] = i + 1;
            continue;
        }
    }
    return answer;
}