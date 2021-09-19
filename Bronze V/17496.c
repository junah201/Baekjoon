//17496  스타후르츠

#include <stdio.h>

int N,T,C,P;

int main() {
    scanf("%d %d %d %d",&N,&T,&C,&P);
    printf("%d",(N-1)/T*C*P);
    return 0;
}