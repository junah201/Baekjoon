/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;
int inp[20][20];
int DP[20][20][3];

int main()
{
    scanf("%d", &N);
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
            scanf("%d", &inp[y][x]);

    DP[1][2][0] = 1;

    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
        {
            if (inp[y][x] == 1)
                continue;
            // 가로 + 가로
            DP[y][x][0] += DP[y][x - 1][0];
            // 대각선 + 가로
            DP[y][x][0] += DP[y][x - 1][2];

            // 세로 + 세로
            DP[y][x][1] += DP[y - 1][x][1];
            // 대각선 + 세로
            DP[y][x][1] += DP[y - 1][x][2];

            if (!inp[y - 1][x] && !inp[y][x - 1])
            {
                // 가로 + 대각선
                DP[y][x][2] += DP[y - 1][x - 1][0];
                // 세로 + 대각선
                DP[y][x][2] += DP[y - 1][x - 1][1];
                // 대각선 + 대각선
                DP[y][x][2] += DP[y - 1][x - 1][2];
            }
        }

    printf("%d", DP[N][N][0] + DP[N][N][1] + DP[N][N][2]);

    return 0;
}