//2869  달팽이는 올라가고 싶다

#include <stdio.h>

int main() {
    int A,B,V;
    scanf("%d %d %d",&A,&B,&V);
    if((V-B)%(A-B)==0) printf("%d",(V-B)/(A-B));
    else printf("%d",((V-B)/(A-B))+1);
    return 0;
}