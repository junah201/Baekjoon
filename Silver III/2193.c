//2193  이친수

#include <stdio.h>

int N;
long long zero[100],one[100];

int main() {
    scanf("%d",&N);
    zero[1]=0;
    one[1]=1;
    zero[2]=1;
    one[2]=0;
    for(int i=3;i<=N;i++) {
        zero[i]=zero[i-1]+one[i-1];
        one[i]=zero[i-1];
    }
    printf("%lld",zero[N]+one[N]);
    return 0;
}