//14465  소가 길을 건너간 이유 5

#include <stdio.h>

int arr[100000];
int N,K,B,sum=0,min=100001,temp;

int main() {
    //입력
    scanf("%d %d %d",&N,&K,&B);
    for(int i=0;i<B;i++) {
        scanf("%d",&temp);
        arr[temp-1]=1;
    }
    //시작값
    for(int i=0;i<K;i++) {
        sum+=arr[i];
    }
    min=sum;
    //슬라이싱
    for(int i=0;i<N-K;i++) {
        sum-=arr[i];
        sum+=arr[i+K];
        if(sum<min) min=sum;
    }
    printf("%d",min);
    return 0;
}