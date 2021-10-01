//10101  삼각형 외우기

#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b+c!=180) printf("Error");
    else if(a==b&&c==b) printf("Equilateral");
    else if(a==b||b==c||a==c) printf("Isosceles");
    else printf("Scalene");
    return 0;
}