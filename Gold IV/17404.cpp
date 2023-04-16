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

signed main()
{
    int N, ans = INT_MAX;
    scanf("%lld", &N);
    vector<vector<int>> A(N, vector<int>(3));

    for (int i = 0, R, G, B; i < N; i++)
    {
        scanf("%lld %lld %lld", &A[i][0], &A[i][1], &A[i][2]);
    }

    vector<vector<int>> DP(N, vector<int>(3));

    DP[0][0] = A[0][0];
    DP[0][1] = A[0][1];
    DP[0][2] = A[0][2];

    for (int k = 0; k <= 2; k++)
    {
        for (int i = 0; i <= 2; i++)
        {
            DP[0][i] = INT_MAX;
        }

        DP[0][k] = A[0][k];

        for (int i = 1; i < N; i++)
        {
            DP[i][0] = A[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
            DP[i][1] = A[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
            DP[i][2] = A[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
        }

        for (int i = 0; i <= 2; i++)
        {
            if (i == k)
                continue;
            ans = min(ans, DP[N - 1][i]);
        }
    }

    printf("%lld", ans);

    return 0;
}