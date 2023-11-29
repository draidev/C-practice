char** solution(const char* names[], size_t names_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*)*names_len);
    
    int idx = 0;
    int j = 0;
    for (int i=0; i<names_len; i++) {
        if (i%5==0) {
            answer[j] = strdup(names[i]); 
            j++;
        }
    }
    
    return answer;
}