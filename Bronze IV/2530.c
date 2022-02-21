//2530  인공지능 시계

#include <stdio.h>

int A,B,C,D;

int main() {
    scanf("%d %d %d %d",&A,&B,&C,&D);
    C+=D;
    while(1) {
        if(C>=60){
            C-=60;
            B+=1;
        } else break;
    }

    while(1) {
        if(B>=60){
            B-=60;
            A+=1;
        } else break;
    }

    while(1) {
        if(A>=24){
            A-=24;
        } else break;
    }

    printf("%d %d %d",A,B,C);
    return 0;
}