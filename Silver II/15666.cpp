//15666 N과 M (12)

#include <stdio.h>
#include <algorithm>

int N,M,idx;
int input[8],result[8];
int value[8];

int f(int idx,int start) {
    if(idx==M) {
        for(int i=0;i<M;i++) {
            printf("%d ",result[i]);
        }
        printf("\n");
        return 0;
    }
    for(int i=start;i<=N;i++) {
        result[idx]=value[i];
        f(idx+1,i);
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    std::sort(input,input+N);
    value[0]=input[0];
    for(int i=1;i<N;i++) {
        if(input[i]!=input[i-1]) {
            idx++;
            value[idx]=input[i];
        }
    }
    N=idx;
    f(0,0);
    return 0;
}