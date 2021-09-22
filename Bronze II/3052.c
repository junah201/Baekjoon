//3052  나머지

#include <stdio.h>

int check[42] = {0,};
int N;

int main() {
    for(int i=0;i<10;i++) {
        scanf("%d",&N);
        check[N%42] = 1;
    }
    N=0;
    for(int i=0;i<42;i++) if(check[i]==1) N+=1;
    printf("%d",N);
}