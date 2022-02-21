//2559  수열

#include <stdio.h>

int N,K,A[100000],sum,max;

int main() {
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<K;i++) sum+=A[i];
    max = sum;
    for(int i=0;i<N-K;i++) {
        sum-=A[i];
        sum+=A[i+K];
        if(sum>max) max=sum;
    }
    printf("%d",max);
    return 0;
}