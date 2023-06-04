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

int N;
vector<vector<int>> graph, init_graph;
vector<tuple<int, int, int>> loads;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

vector<vector<int>> get()
{
    vector<vector<int>> new_graph(N, vector<int>(N, INT_MAX));
    for (auto [x, y, value] : loads)
    {
        new_graph[x][y] = min(new_graph[x][y], value);
        new_graph[y][x] = min(new_graph[y][x], value);
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    new_graph[i][j] = 0;

                new_graph[i][j] = min(new_graph[i][j], new_graph[i][k] + new_graph[k][j]);
            }
        }
    }

    return new_graph;
}

signed main()
{
    scanf("%lld", &N);
    init_graph.resize(N, vector<int>(N, INT_MAX));
    graph.resize(N, vector<int>(N, INT_MAX));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &init_graph[y][x]);
        }
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = y + 1; x < N; x++)
        {
            pq.emplace(init_graph[y][x], x, y);
        }
    }

    while (!pq.empty())
    {
        graph = get();
        auto [value, x, y] = pq.top();
        pq.pop();

        if (graph[y][x] == value)
            continue;

        loads.emplace_back(x, y, value);

        dprintf("%lld : (%lld, %lld)\n", value, x, y);
    }

    graph = get();
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            dprintf("%lld ", graph[y][x]);
            if (graph[y][x] != init_graph[y][x])
            {
                printf("-1");
                return 0;
            }
        }
        dprintf("\n");
    }

    int ans = 0;
    for (auto [x, y, value] : loads)
    {
        ans += value;
    }

    printf("%lld", ans);

    return 0;
}