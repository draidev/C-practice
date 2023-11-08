#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int *p;
    int min_index, min_num, temp;
    p = (int*)malloc(sizeof(int)*1000);

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (p[min_index] > p[j]) {
                min_index = j;
            }
        }
        temp = p[i];
        p[i] = p[min_index];
        p[min_index] = temp;
    }

    int sum_p = 0;
    int result = 0;
    for(i=0; i<n; i++){
        sum_p += p[i];
        result += sum_p;
    }
    printf("%d", result);
    
    free(p);
    return 0;
}