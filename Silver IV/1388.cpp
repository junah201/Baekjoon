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

int Y, X;
vector<vector<char>> inp;
vector<vector<bool>> visited;
int ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    visited[y][x] = true;
    int start_i = 0;
    int end_i = 0;
    if (inp[y][x] == '-')
    {
        start_i = 0;
        end_i = 2;
    }
    else
    {
        start_i = 2;
        end_i = 4;
    }
    for (int i = start_i; i < end_i; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || ry < 0 || rx >= X || ry >= Y)
            continue;

        if (inp[ry][rx] != inp[y][x])
            continue;

        if (visited[ry][rx])
            continue;

        dfs(rx, ry);
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<char>(X));
    visited.resize(Y, vector<bool>(X, false));
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &inp[y][x]);
        }
    }

    int ans = 0;
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (visited[y][x])
                continue;
            dfs(x, y);
            ans++;
        }
    }
    printf("%lld", ans);

    return 0;
}