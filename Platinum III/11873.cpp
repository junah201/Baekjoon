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

int X, Y, inp[1002][1002], high[1002][1002];

int get_max_sum(int level)
{
    int result = 0;

    stack<pair<int, int>> s;
    s.emplace(0, 0);
    high[level][X + 1] = 0;
    for (int i = 1; i <= X + 1; i++)
    {
        while (s.top().second > high[level][i])
        {
            auto [oidx, ovalue] = s.top();
            s.pop();

            while (s.top().second == ovalue)
                s.pop();

            result = max(result, (i - 1 - s.top().first) * ovalue);
            result = max(result, (i - oidx) * ovalue);
        }
        s.emplace(i, high[level][i]);
    }

    return result;
}

void solve()
{
    int ans = 0;

    for (int y = 1; y <= Y; y++)
    {
        for (int x = 1; x <= X; x++)
        {
            scanf("%lld", &inp[y][x]);
        }
    }

    for (int y = 1; y <= Y; y++)
    {
        for (int x = 1; x <= X; x++)
        {
            if (inp[y][x] == 0)
                high[y][x] = 0;
            else
                high[y][x] = high[y - 1][x] + 1;
            dprintf("%lld ", high[y][x]);
        }
        dprintf("\n");
    }

    for (int i = 1; i <= Y; i++)
    {
        ans = max(ans, get_max_sum(i));
    }
    printf("%lld\n", ans);
}

signed main()
{
    while (true)
    {
        scanf("%lld %lld", &Y, &X);
        if (X == 0 && Y == 0)
            break;
        solve();
    }

    return 0;
}