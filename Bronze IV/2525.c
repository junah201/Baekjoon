//2525  오븐 시계

#include <stdio.h>

int A,B,C;

int main() {
    scanf("%d %d\n%d",&A,&B,&C);
    B+=C;
    while(B>=60) {
        B-=60;
        A++;
    }
    while(A>=24) {
        A-=24;
    }
    printf("%d %d\n",A,B);
    return 0;
}