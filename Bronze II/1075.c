//1075  나누기

#include <stdio.h>

long long int N,F;

int main() {
    scanf("%d %d",&N,&F);
    N=N/100*100;
    for(int i=0;i<100;i++) {
        if((N+i)%F==0){
            if(i<10) printf("0%d",i);
            else printf("%d",i);
            break;
        }
    }
    return 0;
}