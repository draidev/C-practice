#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) {int t; t=a; a=b; b=t;}

void bubble_sort(int *base, int n);

int main() {
    int n, i, j;
    int *p;

    scanf("%d", &n);
    
    p=(int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }

    bubble_sort(p, n);

    int sum_p=0;
    int result=0;
    for(i=0; i<n; i++) {
        sum_p += p[i];
        result += sum_p;
    }

    printf("%d", result);
    
    return 0;    
}

void bubble_sort(int *base, int n) {
    int i, j;
    
    for (i=n; i>1; i--) {
        for (j=1; j<i; j++) {
            if (base[j-1] > base[j]) {
                SWAP(base[j-1], base[j]);
            }
        }
    }
}