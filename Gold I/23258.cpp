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

int N, Q;
vector<vector<int>> init_graph;
vector<vector<vector<int>>> graph;

signed main()
{
    scanf("%lld %lld", &N, &Q);
    init_graph.resize(N + 1, vector<int>(N + 1, INT_MAX));
    graph.resize(N + 2, vector<vector<int>>(N + 1, vector<int>(N + 1, INT_MAX)));

    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
        {
            scanf("%lld", &graph[0][y][x]);
            if (graph[0][y][x] == 0)
                graph[0][y][x] = INT_MAX;
        }

    for (int k = 1; k <= N; k++)
    {
        for (int s = 1; s <= N; s++)
        {
            for (int e = 1; e <= N; e++)
            {
                if (s == e)
                    continue;

                graph[k][s][e] = min(graph[k - 1][s][e], graph[k - 1][s][k] + graph[k - 1][k][e]);
            }
        }
    }

    while (Q--)
    {
        int c, s, e;
        scanf("%lld %lld %lld", &c, &s, &e);

        int ans = graph[c - 1][s][e];

        if (s == e)
            printf("0\n");
        else if (ans >= INT_MAX)
            printf("-1\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
