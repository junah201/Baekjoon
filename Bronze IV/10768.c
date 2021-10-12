//10768  특별한 날

#include <stdio.h>

int y,d;

int main() {
    scanf("%d %d",&y,&d);
    if(y<2) printf("Before");
    else if(y>2) printf("After");
    else if(d==18) printf("Special");
    else if(d<18) printf("Before");
    else printf("After");
    return 0;
}