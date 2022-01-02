//11728  배열 합치기

#include <stdio.h>
#include <algorithm>

int N,M,A[2000000];

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<M;i++) scanf("%d",&A[N+i]);
    std::sort(A,A+N+M);
    for(int i=0;i<N+M;i++) {
        if(A[i]!=A[i+1]) printf("%d ",A[i]);
    }
    if(A[N+M-1]==0) printf("0");
    return 0;
}

/*
int N,M,i,j,k,temp;
int A[1000000],B[1000000],C[2000000];

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<M;i++) scanf("%d",&B[i]);

    while(1) {
        if (i==N && j==M) break;
        while(A[i]==A[i+1] && i<N) {
            i++;
        }
        while(B[j]==B[j+1] && j<M) {
            j++;
        }
        if (i==N) C[k++] = B[j++];
        else if (j==M) C[k++] = A[i++];
        else if (A[i]<B[j]) C[k++] = A[i++];
        else if (A[i]>B[j]) C[k++] = B[j++];
        else if (A[i]==B[j]) {
            C[k++] = A[i++];
            j++;
        }
    }
    for(int i=0;i<k;i++) printf("%d ",C[i]);
    return 0;
}
*/