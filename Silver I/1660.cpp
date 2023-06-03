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

int N, ans, max_idx;
vector<int> DP(1000, INT_MAX);
vector<int> DP2(300002, INT_MAX);
// n * n - (n - 1) * (n -1)

signed main()
{
    scanf("%lld", &N);

    DP[0] = 0;
    for (int i = 1;; i++)
    {
        DP[i] = DP[i - 1] + i;
        max_idx = i;
        if (DP[i] >= N)
            break;
    }

    for (int i = 1;; i++)
    {
        DP[i] = DP[i] + DP[i - 1];
        if (DP[i] > N)
        {
            break;
        }
        else if (DP[i] == N)
        {
            DP2[DP[i]] = 1;
            break;
        }
        dprintf("%lld : %lld\n", i, DP[i]);
        DP2[DP[i]] = 1;
    }
    dprintf("\n");

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1;; j++)
        {
            if (i - DP[j] <= 0)
                break;
            if (i - DP[j] > N)
                break;
            DP2[i] = min(DP2[i], DP2[i - DP[j]] + 1);
        }
        // dprintf("%lld : %lld\n", i, DP2[i]);
    }
    // dprintf("\n");

    printf("%lld", DP2[N]);

    return 0;
}