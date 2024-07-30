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

int X, Y, ans = INF;
vector<vector<int>> inp;

void get(int x, int y, int before_direction, int now)
{
    if (x < 0 || x >= X)
        return;
    now += inp[y][x];
    // printf("(%lld, %lld) %lld : %lld\n", x, y, before_direction, now);
    if (y == Y - 1)
    {
        ans = min(ans, now);
        return;
    }

    for (int d = -1; d <= 1; d++)
    {
        if (d == before_direction)
            continue;
        get(x + d, y + 1, d, now);
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &inp[y][x]);

    for (int x = 0; x < X; x++)
    {
        get(x, 0, -1000, 0);
    }

    printf("%lld", ans);

    return 0;
}