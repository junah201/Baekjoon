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

int N, M, Q;
vector<pair<int, int>> dog;
vector<vector<pair<int, int>>> graph;

signed main()
{
    scanf("%lld %lld %lld", &N, &M, &Q);
    dog.resize(N + 1);
    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%lld", &tmp);
        dog[i] = {tmp, i};
    }

    graph.resize(N + 1, vector<pair<int, int>>(N + 1, {INT_MAX, INT_MAX}));

    while (M--)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        graph[a][b].first = min(graph[a][b].first, c);
        graph[a][b].second = max(dog[a].first, dog[b].first);
        graph[b][a].first = min(graph[b][a].first, c);
        graph[b][a].second = max(dog[a].first, dog[b].first);
    }

    sort(dog.begin(), dog.end());

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            if (graph[y][x].first == INT_MAX)
                dprintf("-1 ");
            else
                dprintf("%lld ", graph[y][x].first);
        }
        dprintf("\n");
    }

    for (auto [value, k] : dog)
    {
        for (int s = 1; s <= N; s++)
        {
            for (int e = 1; e <= N; e++)
            {
                if (s == e)
                    continue;
                if (graph[s][k].first == INT_MAX || graph[k][s].first == INT_MAX)
                    continue;

                if (graph[s][e].first + graph[s][e].second > graph[s][k].first + graph[k][e].first + max({graph[s][k].second, graph[k][e].second, value}))
                {
                    dprintf("(%lld %lld %lld);%lld %lld\n", s, e, k, graph[s][k].first, graph[k][e].first);
                    graph[s][e].first = graph[s][k].first + graph[k][e].first;
                    graph[s][e].second = max({graph[s][k].second, graph[k][e].second, value});
                    dprintf("(%lld);\n", graph[s][e].first + graph[s][e].second);
                }
            }
        }
    }

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            if (graph[y][x].first == INT_MAX)
                dprintf("-1 ");
            else
                dprintf("%lld ", graph[y][x].first);
        }
        dprintf("\n");
    }

    while (Q--)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        if (graph[a][b].first >= INT_MAX)
            printf("-1\n");
        else
            printf("%lld\n", graph[a][b].first + graph[a][b].second);
    }

    return 0;
}