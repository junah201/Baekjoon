//16395  파스칼의 삼각형

#include <stdio.h>

int DP[31][31];
int N,K;

int main() {
    scanf("%d %d",&N,&K);
    DP[0][0] = 1;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) DP[i][j] = 1;
            else DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
        }
    }
    printf("%d",DP[N-1][K-1]);
    return 0;
}