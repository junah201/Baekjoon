/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int X, Y;
vector<vector<int>> inp;
vector<vector<int>> dp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X));
    dp.resize(Y, vector<int>(X, -1));

    queue<tuple<int, int, int>> q;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf("%lld", &inp[y][x]);
            if (inp[y][x] == 0)
            {
                dp[y][x] = 0;
            }
            else if (inp[y][x] == 1)
            {
                dp[y][x] = INF;
            }
            else if (inp[y][x] == 2)
            {
                dp[y][x] = 0;
                q.emplace(x, y, 0);
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, cnt] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || ry < 0 || rx >= X || ry >= Y)
                continue;

            if (inp[y][x] == 0)
                continue;

            if (dp[ry][rx] <= cnt + 1)
                continue;

            dp[ry][rx] = cnt + 1;
            q.emplace(rx, ry, cnt + 1);
        }
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (dp[y][x] == INF)
                printf("-1 ");
            else
                printf("%lld ", dp[y][x]);
        }
        printf("\n");
    }

    return 0;
}