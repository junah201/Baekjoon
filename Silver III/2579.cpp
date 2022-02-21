// 2579 계단 오르기
// https://www.acmicpc.net/source/39414750

#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int N, max;
int map[302];
int DP[302];

int get(int idx)
{
    if (DP[idx] == 0)
        DP[idx] = max(get(idx - 2), get(idx - 3) + map[idx - 1]) + map[idx];
    return DP[idx];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &map[i]);
    DP[0] = map[0];
    DP[1] = max(map[0] + map[1], map[1]);
    DP[2] = max(map[0] + map[2], map[1] + map[2]);

    printf("%d", get(N - 1));

    return 0;
}