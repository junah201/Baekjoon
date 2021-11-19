//12847  꿀 아르바이트

#include <stdio.h>

int N,M;
long long int sum=0,max;
int map[1000000];

int main() {
    //입력
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) {
        scanf("%d",&map[i]);
    }
    //시작값
    for(int i=0;i<M;i++) {
        sum+=map[i];
    }
    max=sum;
    //슬라이싱
    for(int i=0;i<N-M;i++) {
        sum-=map[i];
        sum+=map[i+M];
        if(sum>max) max=sum;
    }
    printf("%lld",max);
    return 0;
}