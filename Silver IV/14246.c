//14246  K보다 큰 구간

#include <stdio.h>

int N,K,map[200000],sum[200000];

int tp() {
    int low, high, cnt=0;
    low = 0;
    high = 1;
    while(high<=N) {
        printf("%d %d\n",low,high);
        if(sum[high]-sum[low]>=K) {
            cnt++;
        }
        if(sum[high]-sum[low]>=K) {
            low++;
        }
        else {
            high++;
        }
    }
    return cnt;
}

int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&map[i]);
    sum[1] = map[1];
    for(int i=1;i<=N;i++) sum[i] = sum[i-1]+map[i];
    scanf("%d",&K);
    printf("%d\n",tp());
    return 0;
}