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
vector<int> DP;
vector<pair<int, int>> inp;

signed main()
{
    scanf("%lld", &N);
    DP.resize(N, 0);
    inp.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }

    for (int i = 0; i < N; i++)
    {
        int tmp_max = 0;
        for (int prev = 0; prev < i; prev++)
        {
            tmp_max = max(tmp_max, DP[prev]);
        }
        auto [t, p] = inp[i];
        if (i + t - 1 >= N)
            continue;

        DP[i + t - 1] = max(DP[i + t - 1], tmp_max + p);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, DP[i]);
    }
    printf("%lld", ans);

    return 0;
}