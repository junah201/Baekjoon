//16480  외심과 내심은 사랑입니다

#include <stdio.h>

int main() {
    long long int R,r;
    scanf("%lld %lld",&R,&r);
    printf("%lld\n",R*R-2*R*r);
    return 0;
}