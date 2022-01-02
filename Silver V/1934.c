//1934  최소공배수

#include <stdio.h>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int T,A,B;

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d %d",&A,&B);
        printf("%d\n",A*B/gcd(max(A,B),min(A,B)));
    }
    return 0;
}