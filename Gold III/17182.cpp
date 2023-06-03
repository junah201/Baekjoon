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

int N, K, all_visited, ans = INT_MAX;
vector<vector<int>> graph;
int bits[12];

int xy_to_idx(int x, int y)
{
    return y * N + x;
}

void dfs(int idx, int time, int check)
{
    if (check == all_visited)
    {
        ans = min(ans, time);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (check & bits[i])
            continue;

        dfs(i, time + graph[idx][i], check | bits[i]);
    }
}

signed main()
{

    scanf("%lld %lld", &N, &K);
    graph.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        bits[i] = 1 << i;
        all_visited = all_visited | bits[i];
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &graph[y][x]);
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int s = 0; s < N; s++)
        {
            for (int e = 0; e < N; e++)
            {
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
            }
        }
    }

    dfs(K, 0, bits[K]);

    printf("%lld", ans);

    return 0;
}