//2884	알람 시계

#include <stdio.h>

int H,M;

int main() {
    scanf("%d %d",&H,&M);
    M-=45;
    if(M<0) {
        H-=1;
        M+=60;
    }
    if(H<0) H+=24;
    printf("%d %d",H,M);
    return 0;
}