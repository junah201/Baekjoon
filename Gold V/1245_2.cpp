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

int X, Y;
vector<vector<int>> graph, visited;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool flag;
int ans = 0;

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

        if (graph[y][x] < graph[ny][nx])
            flag = false;

        if (visited[ny][nx])
            continue;

        if (graph[y][x] == graph[ny][nx])
        {
            visited[ny][nx] = 1;
            dfs(nx, ny);
        }
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    graph.resize(Y, vector<int>(X, 0));
    visited.resize(Y, vector<int>(X, 0));

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &graph[y][x]);

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (visited[y][x])
                continue;

            flag = true;
            dfs(x, y);
            if (flag)
                ans += 1;
        }
    }

    printf("%lld", ans);

    return 0;
}