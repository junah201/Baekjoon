//20499  Darius님 한타 안 함?

#include <stdio.h>

int k,d,a;

int main() {
    scanf("%d/%d/%d",&k,&d,&a);
    if(k+a<d||d==0) printf("hasu");
    else printf("gosu");
    return 0;
}