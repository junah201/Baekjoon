//1072  게임

#include <stdio.h>

long long X,Y;

long long bs() {
    long long start = 1;
    long long end = X;
    long long mid;
    while(start<=end) {
        mid = (start+end)/2;
        if(Y*100/X<(Y+mid)*100/(X+mid)) end = mid-1;
        else start = mid+1;
    }
    return start;
}

int main() {
    scanf("%lld %lld",&X,&Y);
    if((Y*100)/X>=99) {
        printf("-1");
        return 0;
    }
    printf("%lld",bs());
    return 0;
}