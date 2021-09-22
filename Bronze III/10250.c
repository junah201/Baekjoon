//10250  ACM 호텔

#include <stdio.h>

int T,H,W,N;

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d %d %d",&H,&W,&N);
        if(N%H==0) printf("%d\n",H*100+N/H);
        else printf("%d\n",(N%H)*100+N/H+1);
    }
    return 0;
}