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

int ans = 0;
int X, Y, T, D;
vector<vector<int>> inp, graph;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int xy_to_idx(int x, int y)
{
    return x + y * X;
}

signed main()
{
    scanf("%lld %lld %lld %lld", &Y, &X, &T, &D);

    inp.resize(Y, vector<int>(X));
    graph.resize(X * Y, vector<int>(X * Y, INT_MAX));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            char tmp;
            scanf(" %1c", &tmp);
            if (tmp > 90)
                tmp -= 6;

            inp[y][x] = tmp - 'A';
            dprintf("%lld ", inp[y][x]);
        }
        dprintf("\n");
    }
    dprintf("\n");

    for (int i = 0; i < X * Y; i++)
    {
        graph[i][i] = 0;
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                    continue;

                if (inp[ny][nx] - inp[y][x] > T || inp[y][x] - inp[ny][nx] > T)
                    continue;

                if (inp[y][x] < inp[ny][nx] && (inp[ny][nx] - inp[y][x]) > T)
                    continue;
                int ntime = 0;
                if (inp[y][x] < inp[ny][nx])
                    ntime += (inp[ny][nx] - inp[y][x]) * (inp[ny][nx] - inp[y][x]);
                else
                    ntime += 1;

                graph[xy_to_idx(x, y)][xy_to_idx(nx, ny)] = ntime;
            }
        }
    }

    for (int k = 0; k < X * Y; k++)
    {
        for (int i = 0; i < X * Y; i++)
        {
            for (int j = 0; j < X * Y; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < X * Y; i++)
    {
        for (int j = 0; j < X * Y; j++)
        {
            dprintf("%lld ", graph[i][j]);
        }
        dprintf("\n");
    }
    dprintf("\n");

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            dprintf("%lld ", graph[0][xy_to_idx(x, y)] + graph[xy_to_idx(x, y)][0]);
            if (graph[0][xy_to_idx(x, y)] + graph[xy_to_idx(x, y)][0] > D)
                continue;

            ans = max(ans, inp[y][x]);
        }
        dprintf("\n");
    }

    printf("%lld", ans);
    return 0;
}