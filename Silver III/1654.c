//1654  랜선 자르기

#include <stdio.h>

int K,N,max;
long long map[10000];

long long int search(long long start, long long end) {
    if(start>end) return end;
    long long mid=(start+end)/2, cnt=0;
    for(int i=0;i<K;i++) cnt += map[i] / mid;
    if(cnt < N) return search(start,mid-1);
    return search(mid+1,end);
}

int main() {
    scanf("%d %d",&K,&N);
    for(int i=0;i<K;i++) {
        scanf("%lld",&map[i]);
        if(max < map[i]) max = map[i];
    }
    printf("%lld",search(1,max));
    return 0;
}