//15650  N과 M (2)

#include <stdio.h>

int N,M;
int result[8],check[8];

int f(int idx,int start) {
    if(idx==M) {
        for(int i=0;i<M;i++) {
            printf("%d ",result[i]);
        }
        printf("\n");
        return 0;
    }
    for(int i=start;i<N;i++) {
            check[i]=1;
            result[idx]=i+1;
            f(idx+1,i+1);
            check[i]=0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    f(0,0);
    return 0;
}