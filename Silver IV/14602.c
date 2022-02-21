//14602  소금과 후추 (Small)

#include <stdio.h>

int M,N,K,W,sum;
int map[30][30];

int main() {
    scanf("%d %d %d %d", &M, &N, &K, &W);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    //초기값
    sum=0;
    for(int i=0;i<W;i++) {
        for(int j=0;j<W;j++) {
            sum+=map[i][j];
        }
    }
    printf("%d ",sum/(W*W));

    return 0;
}