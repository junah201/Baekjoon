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

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};

int X, Y, ans = 0;
vector<vector<char>> inp;

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<char>(X));

    queue<pair<int, int>> q;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &inp[y][x]);

            if (inp[y][x] == 'I')
            {
                inp[y][x] = 'O';
                q.emplace(x, y);
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || ry < 0 || rx >= X || ry >= Y)
                continue;

            if (inp[ry][rx] == 'X')
                continue;

            if (inp[ry][rx] == 'P')
                ans++;

            inp[ry][rx] = 'X';
            q.emplace(rx, ry);
        }
    }

    if (ans)
        printf("%lld", ans);
    else
        printf("TT");

    return 0;
}