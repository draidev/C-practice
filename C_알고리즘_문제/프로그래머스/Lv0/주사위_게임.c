#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int c) {
    int answer = 0;
    
    if (a != b && b != c && c != a)
        answer = a + b + c;
    else if ((a == b && a != c) || (b == c && c != a) || (c == a && a != b))
        answer = (a + b + c)*(mypow(a, 2) + mypow(b, 2) + mypow(c, 2));
    else answer = (a + b + c) * (mypow(a, 2) + mypow(b, 2) + mypow(c, 2)) * (mypow(a, 3) + mypow(b, 3) + mypow(c, 3));
    return answer;
}
             
int mypow(int num, int cnt) {
    if (cnt > 0)
        return num * pow(num, cnt - 1);
    else 
        return 1;
}