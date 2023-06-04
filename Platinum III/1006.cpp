/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

void calu_dp(int const &N, int const &W, vector<vector<int>> &area, vector<vector<int>> &dp)
{

    for (int i = 1; i < N; i++)
    {
        int up = area[0][i] + area[0][i - 1] <= W ? 1 : 2;
        int down = area[1][i] + area[1][i - 1] <= W ? 1 : 2;
        int ver = area[0][i] + area[1][i] <= W ? 1 : 2;

        // ㅁ
        // ㅁㅁ
        dp[i][0] = min({dp[i - 1][1] + down, dp[i - 1][2] + 1});
        // ㅁㅁ
        // ㅁ
        dp[i][1] = min(dp[i - 1][0] + up, dp[i - 1][2] + 1);
        // ㅁㅁ
        // ㅁㅁ
        if (i == 1)
            dp[i][2] = min({dp[i - 1][2] + ver, up + down, dp[i - 1][0] + up + 1, dp[i - 1][1] + down + 1});
        else
            dp[i][2] = min({dp[i - 1][2] + ver, dp[i - 2][2] + up + down, dp[i - 1][0] + up + 1, dp[i - 1][1] + down + 1});
    }
}

void solve()
{
    int N, W, ans = INT_MAX;
    scanf("%lld %lld", &N, &W);

    vector<vector<int>> area(2, vector<int>(N, 0));
    vector<vector<int>> dp(N + 2, vector<int>(3, INT_MAX));

    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &area[y][x]);
        }
    }

    if (N == 1)
    {
        printf("%lld\n", area[0][0] + area[1][0] <= W ? 1 : 2);
        return;
    }

    int t_up = area[0][0];
    int t_down = area[1][0];

    // 연결 X
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = area[0][0] + area[1][0] <= W ? 1 : 2;
    calu_dp(N, W, area, dp);
    ans = min(ans, dp[N - 1][2]);

    // 위 연결
    if (area[0][0] + area[0][N - 1] <= W)
    {
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 2;
        area[0][0] = INT_MAX;
        calu_dp(N, W, area, dp);
        ans = min(ans, dp[N - 1][0]);
        area[0][0] = t_up;
    }

    // 아래 연결
    if (area[1][0] + area[1][N - 1] <= W)
    {
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 2;
        area[1][0] = INT_MAX;
        calu_dp(N, W, area, dp);
        ans = min(ans, dp[N - 1][1]);
        area[1][0] = t_down;
    }

    // 둘다 연결
    if (area[0][0] + area[0][N - 1] <= W && area[1][0] + area[1][N - 1] <= W)
    {
        area[0][0] = INT_MAX;
        area[1][0] = INT_MAX;
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 2;
        calu_dp(N, W, area, dp);
        ans = min(ans, dp[N - 2][2]);
    }

    printf("%lld\n", ans);
}

signed main()
{
    int T;
    scanf("%lld", &T);

    while (T--)
        solve();

    dprintf("end");

    return 0;
}

/*
ㅁㅁ
ㅁ

ㅁ
ㅁㅁ

ㅁㅁ
ㅁㅁ

*/