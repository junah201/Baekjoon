//15649  N과 M (1)

#include <stdio.h>

int N,M;
int result[8],check[8];

int f(int idx) {
    if(idx==M) {
        for(int i=0;i<M;i++) {
            printf("%d ",result[i]);
        }
        printf("\n");
        return 0;
    }
    for(int i=0;i<N;i++) {
        if(!check[i]) {
            check[i]=1;
            result[idx]=i+1;
            f(idx+1);
            check[i]=0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    f(0);
    return 0;
}