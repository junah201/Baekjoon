#include <stdio.h>

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

long long get(long long a, long long b){
	if (b == 0) return a;
	else return get(b, a % b);
}

int main () {
    long long N,M; scanf("%lld %lld",&N,&M);
    long long gcd = get(max(N,M),min(N,M));
    printf("%lld",(N*M)/gcd);
    return 0;
}