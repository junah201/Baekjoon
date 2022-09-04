/* Code By [ junah201 ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

ll N;
ll inp[102][102];
ll DP[102][102];

int main()
{
    scanf("%lld", &N);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &inp[y][x]);
        }
    }
    DP[N - 1][N - 1] = 1;
    for (int y = N - 1; y >= 0; y--)
    {
        for (int x = N - 1; x >= 0; x--)
        {
            if (inp[y][x] == 0)
                continue;

            int rx = x + inp[y][x];
            int ry = y + inp[y][x];
            if (rx < N)
                DP[y][x] += DP[y][rx];
            if (ry < N)
                DP[y][x] += DP[ry][x];
            dprintf("(%lld %lld) %lld\n", x, y, DP[y][x]);
            dprintf("(%lld %lld)\n", rx, ry);
        }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            dprintf("%lld ", DP[y][x]);
        }
        dprintf("\n");
    }
    printf("%lld", DP[0][0]);
    return 0;
}
