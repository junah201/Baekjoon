//2748  피보나치 수 2

#include <stdio.h>

long long int dp[46]={0,};


long long int get(int idx) {
    if(idx==0) return 0;
    else if(idx==1) return 1;
    else if(dp[idx]==0) dp[idx]=get(idx-1)+get(idx-2);
    return dp[idx];
}
int main() {
    //int N; scanf("%d",&N);
    dp[0]=0;
    dp[1]=1;
    for(int i=0;i<=90;i++) printf("%lld\n",get(i));
    return 0;
}