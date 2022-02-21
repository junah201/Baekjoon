//2606  바이러스

#include <stdio.h>

int C,N,A[101];
int t1,t2,cnt;

int main() {
    A[1]=1;
    scanf("%d",&C);
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d %d",&t1,&t2);
        if(A[t1]) A[t2]=1;
        if(A[t2]) A[t1]=1;
    }
    for(int i=2;i<=C;i++) {
        printf("%d ",A[i]);
        if(A[i]) cnt++;
    }
    printf("\n%d\n",cnt);
    return 0;
}