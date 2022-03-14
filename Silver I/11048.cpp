// 11048 이동하기
// https://www.acmicpc.net/source/40373076

#include <bits/stdc++.h>
using namespace std;

int N, M;
int inp[1002][1002];
int DP[1002][1002];

int main()
{
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
        {
            scanf("%d", &inp[y][x]);
            DP[y][x] = inp[y][x] + max(DP[y - 1][x - 1], max(DP[y - 1][x], DP[y][x - 1]));
        }

    printf("%d", DP[N][M]);
    return 0;
}