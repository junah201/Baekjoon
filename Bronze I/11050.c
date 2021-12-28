//11050  이항 계수

#include <stdio.h>

long long int DP[1001][1001];
int N,K;

int main() {
    scanf("%d %d",&N,&K);
    DP[0][0]=1;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) DP[i][j] = 1;
            else DP[i][j] = ((DP[i-1][j]%10007) + (DP[i-1][j-1]%10007))%10007;
        }
    }
    printf("%d",DP[N][K]%10007);
    return 0;
}