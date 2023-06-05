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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int sx, sy, ans;
vector<vector<int>> graph(5, vector<int>(5, -1));
vector<vector<vector<char>>> visited(5, vector<vector<char>>(5, vector<char>(64, false)));

vector<int> bits(7, 0);

void print_graph(int sx, int sy)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (sx == x && sy == y)
                printf("■ ");
            else
                printf("%lld ", graph[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

signed main()
{
    for (int i = 1; i < 7; i++)
    {
        bits[i] = 1 << (i - 1);
        ans = ans | bits[i];
    }

    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            scanf("%lld", &graph[y][x]);

    scanf("%lld %lld", &sy, &sx);

    queue<tuple<int, int, int, int>> q;
    q.emplace(sx, sy, bits[graph[sy][sx]], 1);
    visited[sy][sx][bits[graph[sy][sx]]] = true;

    while (!q.empty())
    {
        auto [x, y, idx, time] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= 5 || ry < 0 || ry >= 5)
                continue;

            if (graph[ry][rx] == -1)
                continue;

            if (visited[ry][rx][idx])
                continue;

            visited[ry][rx][idx] = true;

            if (graph[ry][rx] > 0 && bits[graph[ry][rx]] ^ idx)
            {
                int new_idx = idx | bits[graph[ry][rx]];
                visited[ry][rx][new_idx] = true;
                q.emplace(rx, ry, new_idx, time + 1);

                if (new_idx == ans)
                {
                    printf("%lld", time);
                    return 0;
                }
            }
            else
                q.emplace(rx, ry, idx, time + 1);
        }
    }

    printf("-1");

    return 0;
}