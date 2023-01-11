/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int X, Y;
int inp[1502][1502];
int visited[1502][1502];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = INT_MAX;

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

queue<tuple<int, int, int>> water, next_water;
vector<pair<int, int>> swan;

void print_map()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            dprintf("%c%d ", inp[y][x], visited[y][x]);
        }
        dprintf("\n");
    }
    dprintf("\n\n");
}

void dfs(int x, int y, int idx)
{
    if (ans == 0)
        return;
    if (visited[y][x])
        return;

    visited[y][x] = idx;

    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            continue;

        if (inp[ry][rx] == 'X')
            continue;

        if (visited[ry][rx])
        {
            continue;
        }

        if (inp[ry][rx] == 'L')
        {
            ans = 0;
            return;
        }

        dfs(rx, ry, idx);
    }
}

void dfs_water_to_swan_water(int x, int y, int idx)
{
    dprintf("(%d %d) %d\n", x, y, visited[y][x]);
    visited[y][x] = idx;

    if (ans == 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            continue;

        if (inp[ry][rx] == 'X')
            continue;

        if ((idx == 1 && visited[ry][rx] == 2) || (idx == 2 && visited[ry][rx] == 1))
        {
            ans = 0;
            return;
        }

        if (visited[ry][rx] == 3)
        {
            dfs_water_to_swan_water(rx, ry, idx);
        }
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
            if (inp[y][x] == 'L')
            {
                swan.emplace_back(x, y);
                water.emplace(x, y, 0);
            }
            if (inp[y][x] == '.')
                water.emplace(x, y, 0);
        }
    }

    // 백조1 : 1, 백조2 : 2, 물 : 3

    int tmp_idx = 1;
    for (auto [x, y] : swan)
        dfs(x, y, tmp_idx++);

    while (!water.empty())
    {
        auto [x, y, day] = water.front();
        water.pop();

        int idx = visited[y][x];
        if (idx == 0)
            idx = 3;
        visited[y][x] = idx;

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (visited[ry][rx] == idx)
                continue;

            if (inp[ry][rx] == 'X')
            {
                next_water.emplace(rx, ry, 1);
                visited[ry][rx] = idx;
                continue;
            }
        }
    }

    print_map();

    while (!next_water.empty())
    {

        auto [x, y, day] = next_water.front();

        ans = day;
        next_water.pop();
        inp[y][x] = '.';
        int idx = visited[y][x];

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                continue;

            if (visited[ry][rx] == idx)
                continue;

            if (visited[ry][rx] && inp[ry][rx] == 'X')
                continue;

            if ((idx == 1 || idx == 2) && visited[ry][rx] == 3)
            {
                dprintf("dfs_water_to_swan_water 1\n");
                dprintf("== (%d %d) (%d %d)\n", x, y, rx, ry);
                dfs_water_to_swan_water(rx, ry, idx);
                print_map();
                if (ans == 0)
                {
                    printf("%d", day);
                    return 0;
                }
            }
            else if (idx == 3 && (visited[ry][rx] == 1 || visited[ry][rx] == 2))
            {
                dprintf("dfs_water_to_swan_water 2\n");
                dprintf("== (%d %d) (%d %d)\n", x, y, rx, ry);
                dfs_water_to_swan_water(x, y, visited[ry][rx]);
                print_map();
                if (ans == 0)
                {
                    printf("%d", day);
                    return 0;
                }
            }

            if (inp[ry][rx] == '.' && ((idx == 1 && visited[ry][rx] == 2) || (idx == 2 && visited[ry][rx] == 1)))
            {
                dprintf("== (%d %d) (%d %d) %d\n", x, y, rx, ry, inp[ry][rx] == '.');
                printf("%d", day);
                return 0;
            }

            if (visited[ry][rx] == 0 && inp[ry][rx] == 'X')
            {
                next_water.emplace(rx, ry, day + 1);
                visited[ry][rx] = idx;
            }
        }
        dprintf("%d\n", day);
        print_map();
    }
    print_map();

    return 0;
}