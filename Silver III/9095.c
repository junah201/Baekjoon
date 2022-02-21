//9095  1,2,3 더하기

#include <stdio.h>

int DP[21];

int f(int idx) {
    if(idx==1) return 1;
    else if(idx==2) return 2;
    else if(idx==3) return 4;
    else if(DP[idx]==0) DP[idx]=f(idx-1)+f(idx-2)+f(idx-3);
    return DP[idx];
}

int main() {
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        printf("%d\n",f(N));
    }
    return 0;
}