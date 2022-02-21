//11727  2×n 타일링 2

#include <stdio.h>

int DP[1001];

int f(int idx) {
    if(idx==0) return 0;
    else if(idx==1) return 1;
    else if(idx==2) return 3;
    if(DP[idx]==0) DP[idx]=(f(idx-1)+2*f(idx-2))%10007;
    return DP[idx];
}

int main() {
    int N;
    scanf("%d",&N);
    printf("%d",f(N)%10007);
    return 0;
}