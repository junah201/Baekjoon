#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int DP[2002][2002];
int add[2002][2002];

int main()
{
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%1d", &add[y][x]);

    for (int x = 0; x < M; x++)
        for (int y = 0; y < N; y++)
        {
            DP[y][x] = add[y][x];
            for (int ty = y - 1; ty <= y + 1; ty++)
            {
                if (ty < 0 || ty >= N || x - 1 < 0)
                    continue;
                DP[y][x] = max(DP[y][x], DP[ty][x - 1] + add[y][x]);
            }
        }

    for (int y = 0; y < N; y++)
        ans = max(ans, DP[y][M - 1] - add[y][M - 1]);
    printf("%d", ans);
    return 0;
}