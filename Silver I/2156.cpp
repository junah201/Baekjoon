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

int N, ans = 0;

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N);
    vector<vector<int>> DP(N, vector<int>(2, 0));
    // 1: 전 포도주를 마셨을 때 최대값
    // 0: 전 포도주를 안마셨을 때 최대값

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        DP[i][0] = A[i];
        DP[i][1] = A[i];
    }

    if (N >= 2)
    {
        DP[1][1] = A[0] + A[1];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            DP[i][1] = max(DP[i][1], DP[j][0] + A[i]);
        }
        for (int j = 0; j < i - 1; j++)
        {
            DP[i][0] = max(DP[i][0], max(DP[j][0], DP[j][1]) + A[i]);
        }
        ans = max(ans, DP[i][0]);
        ans = max(ans, DP[i][1]);
    }

    for (int i = 0; i < N; i++)
    {
        dprintf("%lld (%lld) : %lld %lld\n", i, A[i], DP[i][0], DP[i][1]);
    }

    printf("%lld", ans);

    return 0;
}