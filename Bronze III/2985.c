//2985  세 수

#include <stdio.h>

double a,b,c;

int main() {
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a+b==c) printf("%.0lf+%.0lf=%.0lf",a,b,c);
    else if(a-b==c) printf("%.0lf-%.0lf=%.0lf",a,b,c);
    else if(a*b==c) printf("%.0lf*%.0lf=%.0lf",a,b,c);
    else if(a/b==c) printf("%.0lf/%.0lf=%.0lf",a,b,c);
    else if(a==b+c) printf("%.0lf=%.0lf+%.0lf",a,b,c);
    else if(a==b-c) printf("%.0lf=%.0lf-%.0lf",a,b,c);
    else if(a==b*c) printf("%.0lf=%.0lf*%.0lf",a,b,c);
    else if(a==b/c) printf("%.0lf=%.0lf/%.0lf",a,b,c);
    return 0;
}