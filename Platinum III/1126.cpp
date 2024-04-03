/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;
int DP[51][500002];
int inp[51];

signed main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &inp[i]);
    }

    DP[0][0] = 1;
    DP[0][inp[0]] = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= 500000; j++)
        {
            // 블록을 새로 안쌓았을 떄
            DP[i][j] += DP[i - 1][j];
            // 블록을 새로 쌓았을 때
            if (DP[i - 1][j])
            {
                DP[i][j + inp[i]] += DP[i - 1][j];
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= 500000; i++)
    {
        if (DP[N - 1][i] >= 2)
            ans = max(ans, i);
    }
    printf("%lld", ans);

    return 0;
}
