//2420  사파리 월드

#include <stdio.h>

long long int N,M;

int main() {
    scanf("%lld %lld",&N,&M);
	if(N-M<0) printf("%lld",(N-M)*(-1));
	else printf("%lld",N-M);
    return 0;
}