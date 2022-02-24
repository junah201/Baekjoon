// 1904 01타일
// https://www.acmicpc.net/source/39580920

#include <stdio.h>

int N;
int DP[1000000];

int main() {
    DP[1] = 1;
    DP[2] = 2;
    scanf("%d", &N);
    for(int i=3;i<=N;i++) {
        DP[i] = (DP[i-2] % 15746 + DP[i-1] % 15746) % 15746;
    }
    printf("%d\n", DP[N]);
    return 0;
}