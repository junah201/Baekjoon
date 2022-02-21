//14652  나는 행복합니다~

#include <stdio.h>

int N,M,K;

int main() {
    scanf("%d %d %d",&N,&M,&K);
    printf("%d %d",K/M,K%M);
    return 0;
}