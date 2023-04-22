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

int N, M;
vector<int> D;
vector<vector<int>> DP;

signed main()
{
    scanf("%lld %lld", &N, &M);
    D.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &D[i]);
    }

    DP.resize(N, vector<int>(M + 1, 0));

    DP[0][1] = D[0];
    DP[1][0] = D[0];

    for (int i = 1; i < N; i++)
    {
        DP[i][0] = max(DP[i][0], DP[i - 1][0]);
        for (int j = 1; j <= M; j++)
        {
            DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + D[i]);
            if (i + j < N)
            {
                DP[i + j][0] = max(DP[i + j][0], DP[i][j]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            dprintf("%lld ", DP[i][j]);
        }
        dprintf("\n");
    }

    printf("%lld", DP[N - 1][0]);

    return 0;
}