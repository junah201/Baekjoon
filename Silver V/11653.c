//11653  소인수분해

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
    for(int i=2;i<=N;i++) {
        while(N%i==0) {
            printf("%d\n",i);
            N/=i;
        }
    }
    return 0;
}