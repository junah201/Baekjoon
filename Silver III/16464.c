//16464  가주아

#include <stdio.h>

int T,N;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        while(N%2==0 && N>2) {
            N/=2;
        }
        if(N%2==1) printf("Gazua\n");
        else printf("GoHanGang\n");
    }
    return 0;
}