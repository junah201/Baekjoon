//2475  검증수

#include <stdio.h>

int a,b,c,d,e;

int main() {
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    printf("%d",(a*a+b*b+c*c+d*d+e*e)%10);
    return 0;
}