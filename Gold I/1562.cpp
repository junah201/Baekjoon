// 1562 계단수
// https://www.acmicpc.net/source/40658150

#include <bits/stdc++.h>
using namespace std;

int N, mx = (1 << 10), mod = 1000000000, ans;
int DP[102][10][1 << 10];

int main()
{
    scanf("%d", &N);
    if (N < 10)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= 9; i++)
        DP[1][i][1 << i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k < mx; k++)
            {
                if (j == 0)
                    DP[i][0][k | (1 << 0)] = (DP[i][0][k | (1 << 0)] + DP[i - 1][1][k]) % mod;
                else if (j == 9)
                    DP[i][9][k | (1 << 9)] = (DP[i][9][k | (1 << 9)] + DP[i - 1][8][k]) % mod;
                else
                {
                    DP[i][j][k | (1 << j)] = (DP[i][j][k | (1 << j)] + DP[i - 1][j - 1][k]) % mod;
                    DP[i][j][k | (1 << j)] = (DP[i][j][k | (1 << j)] + DP[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++)
        ans = (ans + DP[N][i][mx - 1]) % mod;

    printf("%d", ans);
}