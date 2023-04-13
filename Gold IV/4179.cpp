/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int X, Y;
char inp[1002][1002];
vector<vector<int>> fire(1002, vector<int>(1002, INT_MAX));
bool visited[1002][1002];
pair<int, int> J;
queue<tuple<int, int, int>> fire_q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fire_bfs()
{
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

            if (inp[ry][rx] == '#')
                continue;

            fire[ry][rx] = idx + 1;
            fire_q.emplace(rx, ry, idx + 1);
        }
    }
}

int bfs()
{
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
                return idx;

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
    return -1;
}

void print_bfs()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            printf("%d ", fire[y][x]);
        }
        printf("\n");
    }
}

void print_inp()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            printf("%c ", inp[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %c", &inp[y][x]);
            if (inp[y][x] == 'F')
            {
                fire_q.emplace(x, y, 1);
                fire[y][x] = 1;
            }
            if (inp[y][x] == 'J')
                J = {x, y};
        }
    }

    fire_bfs();
    int result = bfs();

    if (result == -1)
        printf("IMPOSSIBLE");
    else
        printf("%d", result);

    return 0;
}