/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int T;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    vector<vector<int>> fire(Y + 2, vector<int>(X + 2, INT_MAX));
    vector<vector<bool>> visited(Y + 2, vector<bool>(X + 2, false));
    vector<vector<char>> inp(Y + 2, vector<char>(X + 2));
    pair<int, int> J;
    queue<tuple<int, int, int>> fire_q;

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %c", &inp[y][x]);
            if (inp[y][x] == '*')
            {
                fire_q.emplace(x, y, 1);
                fire[y][x] = 1;
            }
            if (inp[y][x] == '@')
                J = {x, y};
        }
    }

    while (!fire_q.empty())
    {
        auto [x, y, idx] = fire_q.front();
        fire_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (fire[ry][rx] != INT_MAX)
                continue;

            if (inp[ry][rx] != '.')
                continue;

            fire[ry][rx] = idx + 1;
            fire_q.emplace(rx, ry, idx + 1);
        }
    }

    queue<tuple<int, int, int>> q;
    q.emplace(J.first, J.second, 1);
    visited[J.second][J.first] = true;

    while (!q.empty())
    {
        auto [x, y, idx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            {
                printf("%d\n", idx);
                return;
            }

            if (inp[ry][rx] == '#')
                continue;

            if (fire[ry][rx] <= idx + 1)
                continue;

            if (visited[ry][rx])
                continue;

            visited[ry][rx] = true;
            q.emplace(rx, ry, idx + 1);
        }
    }
    printf("IMPOSSIBLE\n");
    return;
}

int main()
{
    scanf("%d", &T);
    while (T--)
        solve();

    return 0;
}