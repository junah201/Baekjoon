//2003 수들의 합 2

#include <stdio.h>

int N,M,A[10000];
int start,end,sum,cnt;

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    sum = A[0];
    while(1) {
        if(end==N) break;
        if(sum==M) {
            cnt++;
            sum -= A[start++];
            continue;
        } else if(sum>M) {
            sum -= A[start++];
            continue;
        } else if(sum<M) {
            sum += A[++end];
            continue;
        }
    }
    printf("%d\n",cnt);
    return 0;
}