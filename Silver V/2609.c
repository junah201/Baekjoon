//2609  최대공약수와 최소공배수

#include <stdio.h>

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int get(int a, int b){
	if (b == 0) return a;
	else return get(b, a % b);
}

int main () {
    int N,M; scanf("%d %d",&N,&M);
    int gcd = get(max(N,M),min(N,M));
    printf("%d %d",gcd,(N*M)/gcd);
    return 0;
}