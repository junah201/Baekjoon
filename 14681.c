//14681	사분면 고르기

#include <stdio.h>

int X,Y;

int main() {
    scanf("%d %d",&X,&Y);
    if(X>0 && Y>0) printf("1");
    else if(X<0 && Y>0) printf("2");
    else if(X<0 && Y<0) printf("3");
    else printf("4");
    
    return 0;
}