//24270 미니 버킷 리스트

#include <stdio.h>

int N,K,sum=0,temp;
int DP[500001];

int fac(int idx) {
    if(idx==0) return 1;
    if(DP[idx]==0) DP[idx]=(idx%1000000007*(fac(idx-1))%1000000007)%1000000007;
    return DP[idx];
}

int main() {
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d",&temp);
        sum+=temp;
    }
    int R = K-sum;
    printf("%d",fac(N)*(fac(N+R)/fac(R)));
    // (N+1)! / (K-sum)!
    // (N)! * (N+R)!/R!
    return 0;
}