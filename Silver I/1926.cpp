/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int X, Y;
bool inp[502][502];
int visited[502][502];
int cnt[250002];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy, int idx)
{
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    visited[sy][sx] = idx;
    cnt[idx]++;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (!inp[ry][rx])
                continue;

            if (visited[ry][rx])
                continue;

            visited[ry][rx] = idx;
            cnt[idx]++;

            q.emplace(rx, ry);
        }
    }
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0, tmp; x < X; x++)
        {
            scanf("%d", &tmp);
            inp[y][x] = (tmp == 1);
        }
    }

    int idx = 1;
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x] && !visited[y][x])
            {
                bfs(x, y, idx++);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < idx; i++)
        ans = max(ans, cnt[i]);

    printf("%d\n%d", idx - 1, ans);

    return 0;
}