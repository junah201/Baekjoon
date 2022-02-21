//2805  나무 자르기

#include <stdio.h>

int N,M;
long long map[1000000];

long long bf() {
    long long start=0, end=2000000000,mid,cnt;
    while(start<=end) {
        mid = (start+end)/2;
        cnt = 0;
        for(int i=0;i<N;i++) if(map[i]-mid>0) cnt += map[i]-mid;
        if(cnt<M) end = mid-1;
        else start = mid+1;
    }
    return end;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) {
        scanf("%lld",&map[i]);
    }
    printf("%lld",bf());
    return 0;
}