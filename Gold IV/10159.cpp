/* Code Bk [ junah ]
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

int N, M;
vector<vector<int>> graph;

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1, vector<int>(N + 1, INT_MAX));

    for (int i = 1; i <= N; i++)
        graph[i][i] = 0;

    while (M--)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);

        graph[a][b] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            dprintf("%lld ", graph[y][x]);
        }
        dprintf("\n");
    }

    for (int y = 1; y <= N; y++)
    {
        int cnt = 0;
        for (int x = 1; x <= N; x++)
        {
            if (graph[y][x] == INT_MAX && graph[x][y] == INT_MAX)
                cnt++;
        }
        printf("%lld\n", cnt);
    }

    return 0;
}