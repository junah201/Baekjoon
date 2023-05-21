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

int N;

void solve()
{
    int ans = 0;
    stack<pair<int, int>> s;
    int A[100005];
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (int i = N + 1; i < min((long long)100005, N + 5); i++)
        A[i] = 0;

    s.emplace(0, 0);

    for (int i = 1; i <= N + 1; i++)
    {
        while (s.top().second > A[i])
        {
            auto [oidx, ovalue] = s.top();
            s.pop();
            while (s.top().second == ovalue)
                s.pop();

            auto [tidx, tvalue] = s.top();
            ans = max(ans, max((i - 1 - s.top().first) * ovalue, (i - oidx) * ovalue));
        }
        s.emplace(i, A[i]);
    }

    printf("%lld\n", ans);
}

signed main()
{
    while (true)
    {
        scanf("%lld", &N);
        if (N == 0)
            break;
        solve();
    }

    return 0;
}
