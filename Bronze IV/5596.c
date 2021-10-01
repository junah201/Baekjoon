//5596  시험 점수

#include <stdio.h>

int main() {
    int a1,b1,c1,d1;
    int a2,b2,c2,d2;
    scanf("%d %d %d %d %d %d %d %d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
    if(a1+b1+c1+d1>=a2+b2+c2+d2) printf("%d",a1+b1+c1+d1);
    else printf("%d",a2+b2+c2+d2);
    return 0;
}