//2523  별 찍기 - 13

#include <stdio.h>

int N;

int get(int idx) {
    if(idx==N-1) {
        for(int i=0;i<=idx;i++) printf("*");
        printf(" \n");
        return 0;
    }
    for(int i=0;i<=idx;i++) printf("*");
    printf(" \n");
    get(idx+1);
    for(int i=0;i<=idx;i++) printf("*");
    printf(" \n");
    return 0;
}

int main() {
    scanf("%d",&N);
    get(0);
}