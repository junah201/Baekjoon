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

int N, M;
int S, E;

vector<vector<int>> graph;
vector<int> dist;
vector<vector<int>> parent;

int dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.clear();
    dist.resize(N, INT_MAX);
    parent.clear();
    parent.resize(N);

    pq.emplace(0, S);
    dist[S] = 0;

    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (cost > dist[now])
            continue;

        for (int next = 0; next < N; next++)
        {
            if (graph[now][next] == INT_MAX)
                continue;

            int next_cost = graph[now][next];

            if (cost + next_cost < dist[next])
            {
                dist[next] = cost + next_cost;
                pq.emplace(cost + next_cost, next);
                parent[next].clear();
                parent[next].emplace_back(now);
            }
            else if (cost + next_cost == dist[next])
            {
                parent[next].emplace_back(now);
            }
        }
    }

    return dist[E];
}

void remove_path()
{
    queue<int> tmp_q;
    tmp_q.emplace(E);
    vector<char> visited(N, false);
    visited[E] = true;
    while (!tmp_q.empty())
    {
        int now = tmp_q.front();
        tmp_q.pop();

        for (auto prev : parent[now])
        {
            dprintf("remove %lld to %lld (cost: %lld)\n", prev, now, graph[prev][now]);
            graph[prev][now] = INT_MAX;
            if (visited[prev])
                continue;
            tmp_q.emplace(prev);
            visited[prev] = true;
        }
    }
}

void print_graph()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (graph[y][x] == INT_MAX)
                dprintf("%3d", -1);
            else
                dprintf("%3lld ", graph[y][x]);
        }
        dprintf("\n");
    }
}

void solve()
{
    scanf("%lld %lld", &S, &E);
    graph.clear();
    graph.resize(N, vector<int>(N, INT_MAX));

    for (int i = 0; i < M; i++)
    {
        int u, v, p;
        scanf("%lld %lld %lld", &u, &v, &p);

        graph[u][v] = p;
    }

    int ans = dijkstra();
    print_graph();
    dprintf("ans1: %lld\n", ans);

    if (ans == INT_MAX)
    {
        printf("-1\n");
        return;
    }

    remove_path();
    print_graph();

    ans = dijkstra();
    remove_path();

    if (ans == INT_MAX)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

signed main()
{
    dprintf("start\n");
    while (true)
    {
        scanf("%lld %lld", &N, &M);
        if (N == 0 && M == 0)
            break;
        solve();
    }

    dprintf("END");
    return 0;
}