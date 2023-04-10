/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int X, Y;
char inp[702][702];

int is_movable[702][702];
bool movable_visited[702][702];
bool sua_visited[702][702];

pair<int, int> V, S, T;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void update_movable()
{
    queue<tuple<int, int, int>> q;

    q.emplace(V.first, V.second, 1);
    movable_visited[V.second][V.first] = true;

    while (!q.empty())
    {
        auto [x, y, idx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;

            while (!(nx < 0 || nx >= X || ny < 0 || ny >= Y))
            {
                nx += dx[i];
                ny += dy[i];

                if (inp[ny][nx] == 'I')
                    break;

                if (is_movable[ny][nx])
                    continue;

                is_movable[ny][nx] = idx;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (inp[ry][rx] == 'I')
                continue;

            if (movable_visited[ry][rx])
                continue;

            movable_visited[ry][rx] = true;

            q.emplace(rx, ry, idx + 1);
        }
    }
}

void print_movable()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x] == 'I')
            {
                printf("■ ");
            }
            else
                printf("%d ", is_movable[y][x]);
        }
        printf("\n");
    }
}

bool bfs()
{
    queue<tuple<int, int, int>> q;

    q.emplace(S.first, S.second, 1);
    sua_visited[S.second][S.first] = true;

    while (!q.empty())
    {
        auto [x, y, idx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (inp[ry][rx] == 'I')
                continue;

            if (is_movable[ry][rx] - 1 <= idx)
                continue;

            if (sua_visited[ry][rx])
                continue;

            if (inp[ry][rx] == 'T')
                return true;

            sua_visited[ry][rx] = true;

            q.emplace(rx, ry, idx + 1);
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
        {
            scanf(" %c", &inp[y][x]);

            if (inp[y][x] == 'V')
            {
                V = {x, y};
            }
            if (inp[y][x] == 'Y')
            {
                S = {x, y};
            }
            if (inp[y][x] == 'T')
            {
                T = {x, y};
            }
        }

    update_movable();

    if (bfs())
        printf("YES");
    else
        printf("NO");

    return 0;
}