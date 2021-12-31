//15654 N과 M (5)

#include <stdio.h>
#include <algorithm>

int N,M;
int input[8],check[8],result[8];

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
            result[idx]=input[i];
            f(idx+1);
            check[i]=0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    std::sort(input,input+N);
    f(0);
    return 0;
}