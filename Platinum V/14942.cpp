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

int N, K;
vector<vector<pair<int, int>>> init_graph;
vector<vector<pair<int, int>>> graph; // node cost
queue<pair<int, int>> query;

void bfs()
{
    queue<int> q;
    vector<char> visited(N + 1, false);
    visited[1] = true;
    q.emplace(1);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto [next, cost] : init_graph[now])
        {
            if (visited[next])
                continue;

            visited[next] = true;

            graph[next][1] = make_pair(now, cost);
            q.emplace(next);
        }
    }
}

int dfs(int now, int total)
{
    if (now == 1)
        return 1;

    for (int i = K; i >= 1; i--)
    {
        if (graph[now][i].second > total)
            continue;
        return dfs(graph[now][i].first, total - graph[now][i].second);
    }

    return now;
}

signed main()
{
    scanf("%lld", &N);
    K = std::ceil(std::log2(N));

    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%lld", &tmp);
        query.emplace(i, tmp);
    }

    init_graph.resize(N + 1);
    graph.resize(N + 1, vector<pair<int, int>>(K + 1, {1, 0}));

    for (int i = 0; i < N - 1; i++)
    {
        int s, e, c;
        scanf("%lld %lld %lld", &s, &e, &c);
        init_graph[s].emplace_back(e, c);
        init_graph[e].emplace_back(s, c);
    }

    bfs();

    for (int jump = 2; jump <= K; jump++)
    {
        for (int i = N; i >= 2; i--)
        {
            int prev1 = graph[i][jump - 1].first;

            graph[i][jump] = {
                graph[prev1][jump - 1].first,
                graph[i][jump - 1].second + graph[prev1][jump - 1].second};
        }
    }

    for (int i = 1; i <= K; i++)
    {
        dprintf("=== %lld ===\n", i);
        for (int j = 1; j <= N; j++)
        {
            dprintf("now:%lld prev:%lld cost:%lld\n", j, graph[j][i].first, graph[j][i].second);
        }
    }

    while (!query.empty())
    {
        auto [now, enurgy] = query.front();
        query.pop();

        printf("%lld\n", dfs(now, enurgy));
    }

    return 0;
}