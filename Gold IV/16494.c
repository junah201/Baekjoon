#include <stdio.h>

int N, M, cnt;
int map[22];
int sum[22];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) scanf("%d", &map[i]);
    for(int i=1;i<=N;i++) {
        sum[i] = map[i] + sum[i-1];
        if(sum[i] < 0) {
            sum[i] = 0;
            cnt++;
        }
        printf("%d ", sum[i]);
    }
    return 0;
}