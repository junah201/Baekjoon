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

int X, Y, K;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int>> inp;

signed main()
{
    scanf("%lld %lld %lld", &Y, &X, &K);
    inp.resize(Y, vector<int>(X, 0));

    vector<queue<pair<int, int>>> q(3002);

    for (int i = 0; i < K; i++)
    {
        int x, y, p;
        scanf("%lld %lld %lld", &y, &x, &p);
        q[p + 1].emplace(x - 1, y - 1);
    }

    for (int power = 3001; power >= 1; power--)
    {
        while (!q[power].empty())
        {
            auto [tx, ty] = q[power].front();
            q[power].pop();

            if (inp[ty][tx] >= power)
                continue;

            inp[ty][tx] = power;

            // printf("%lld %lld %lld\n", tx, ty, tp);

            for (int i = 0; i < 4; i++)
            {
                int nx = tx + dx[i];
                int ny = ty + dy[i];

                if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                    continue;

                if (inp[ny][nx] >= power)
                    continue;

                q[power - 1].emplace(nx, ny);
            }
        }
    }

    int ans = 0;
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            dprintf("%lld ", inp[y][x]);
            ans += !!inp[y][x];
        }
        dprintf("\n");
    }

    printf("%lld", ans);

    return 0;
}
