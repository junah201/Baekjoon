//1003  파보나치 함수

#include <stdio.h>

int DP[41]={0,1,1};
int main() {
    int T,N; scanf("%d",&T);
    for(int i=3;i<=40;i++) DP[i]=DP[i-1]+DP[i-2];
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        if(N==0) printf("1 0\n");
        else if(N==1) printf("0 1\n");
        else printf("%d %d\n",DP[N-1],DP[N]);
    }
    return 0;
}
