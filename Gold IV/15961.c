//15961  회전 초밥

#include <stdio.h>

int N,D,K,C;
int cnt=0,max=0,check=0;
int input[3000000];
int output[3001];

int main() {
    //입력
    scanf("%d %d %d %d",&N,&D,&K,&C);
    for (int i=0;i<N;i++) {
        scanf("%d",&input[i]);
    }
    //기본값 입력
    for(int i=0;i<K;i++) {
        output[input[i]]+=1;
        if(output[input[i]]==1) cnt+=1;
    }
    //계산
    for(int i=0;i<=N+K;i++) {
        //슬라이싱
        output[input[i%N]]-=1;
        if(output[input[i%N]]==0) cnt-=1;
        output[input[(i+K)%N]]+=1;
        if(output[input[(i+K)%N]]==1) cnt+=1;
        //C가 있는지 체크
        if(cnt+!output[C]>max) max=cnt+!output[C];
    }
    printf("%d", max);
    return 0;
}