//22973  점프 숨바꼭질

#include <stdio.h>

int main() {
    long long int K, cnt=1, result=1,jump=1;
    scanf("%lld", &K);
    if(K<0) K*=-1;
    if(K%2==0) {
        printf("-1");
        return 0;
    }
    while(result<K) {
        jump*=2;
        result+=jump;
        cnt++;
    }
    if(result==K) printf("%lld",cnt);
    else printf("-1");
    return 0;
}