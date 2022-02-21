//2167  2차원 배열의 합

#include <stdio.h>

int N,M,K;
int map[300][300];
int sum[300][300];

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%d",&map[i][j]);
        }
    }
}