//2577  숫자의 개수

#include <stdio.h>

int number[10] = {0,};
long long int a,b,c;
long long int sum;
int main() {
    scanf("%lld %lld %lld",&a,&b,&c);
    sum = a*b*c;
    while (sum>0) {
        number[sum%10] += 1;
        sum/=10;
    }
    for(int i=0;i<10;i++) {
        printf("%d\n",number[i]);
    }
    return 0;
}