//10025  게으른 백곰

#include <stdio.h>

int N,K,sum,max,limit;
int G[5000000];
int temp_X,temp_G;

int main() {
    //입력
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d %d",&temp_G,&temp_X);
        G[temp_X] = temp_G;
        if(temp_X>limit) limit = temp_X;
    }
    //시작값
    for(int i=0;i<2*K+1;i++) {
        sum += G[i];
    }
    max = sum;
    //슬라이싱
    for(int i=0;i<limit-K+1;i++) {
        sum-=G[i];
        sum+=G[i+2*K+1];
        if(sum>max) max = sum;
    }
    printf("%d",max);
    return 0;
}