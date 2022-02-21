//11659  구간 합 구하기 4

#include <stdio.h>

int N,M,a,b;
int input[100000];
int sum[100001];

int main() {
    scanf("%d %d",&N,&M);
    sum[0] = 0;
    for(int i=0;i<N;i++) {
        scanf("%d",&input[i]);
        sum[i+1] = sum[i] + input[i];
    }
    for(int i=0;i<M;i++) {
        scanf("%d %d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}