//2133  타일 채우기

#include <stdio.h>

int DP[100];

int f(int idx) {
    if(idx%2==1) return 0;
    if(idx==0) return 1;
    else if(idx==2) return 3;
    else if(idx==4) return 11;
    else if(DP[idx]==0) {
        DP[idx]=3*f(idx-2);
        for(int i=idx;i>=4;i-=2) {
            DP[idx]+=2*f(idx-i);
        }
    }
    return DP[idx];
}

int main() {
    int N;
    scanf("%d",&N);
    printf("%d",f(N));
    return 0;
}