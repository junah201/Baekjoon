//15964  이상한 기호

#include <stdio.h>

long long int A,B;

int main() {
    scanf("%lld %lld",&A,&B);
    printf("%lld",(A+B)*(A-B));
    return 0;
}