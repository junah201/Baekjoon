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

int N, ans;
stack<pair<int, int>> s;
int A[100005];

signed main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
    }

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
            dprintf("i : %lld, oidx : %lld, ovalue : %lld\n", i, oidx, ovalue);
            dprintf("tidx : %lld, tvalue : %lld\n", s.top().first, s.top().second);
            dprintf("%lld %lld : %lld %lld\n", (i - 1 - s.top().first) * ovalue, (i - oidx) * ovalue, oidx, ovalue);
            // tmp_area = max((i - 1 - stack[-1][0]) * tmp_list[1], (i - tmp_list[0]) * tmp_list[1])
            ans = max(ans, max((i - 1 - s.top().first) * ovalue, (i - oidx) * ovalue));
        }
        s.emplace(i, A[i]);
    }

    printf("%lld", ans);

    return 0;
}
