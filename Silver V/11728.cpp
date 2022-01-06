//11728  배열 합치기

#include <stdio.h>
#include <algorithm>

int N,M,A[2000000],B[2000000],idxA,idxB;

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<M;i++) scanf("%d",&B[i]);
    A[N] = 999999999;
    B[M] = 999999999;
    while(idxA<N || idxB<M) {
        if(A[idxA]<B[idxB]) {
            printf("%d ",A[idxA++]);
        }
        else{
            printf("%d ",B[idxB++]);
        }
    }
    return 0;
}