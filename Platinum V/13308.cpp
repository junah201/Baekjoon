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
vector<int> cost;
vector<vector<pair<int, int>>> graph;

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1);
    cost.resize(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &cost[i]);

    while (M--)
    {
        int s, e, c;
        scanf("%lld %lld %lld", &s, &e, &c);
        graph[s].emplace_back(e, c);
        graph[e].emplace_back(s, c);
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> dist(N + 1, vector<int>(2502, LONG_LONG_MAX));

    dist[1][cost[1]] = 0;
    for (auto [next, next_dist] : graph[1])
    {
        dist[next][cost[1]] = cost[1] * next_dist;
        pq.emplace(cost[1] * next_dist, cost[1], next);
    }

    while (!pq.empty())
    {
        auto [used_cost, min_cost, now] = pq.top();
        pq.pop();

        if (now == N)
        {
            printf("%lld", used_cost);
            return 0;
        }

        dprintf("now:%lld used:%lld min:%lld\n", now, used_cost, min_cost);

        if (used_cost > dist[now][min_cost])
            continue;

        min_cost = min(min_cost, cost[now]);

        for (auto [next, next_dist] : graph[now])
        {
            if (used_cost + next_dist * min_cost >= dist[next][min_cost])
                continue;

            dist[next][min_cost] = used_cost + next_dist * min_cost;

            dprintf("E : %lld\n", next);

            pq.emplace(used_cost + next_dist * min_cost, min_cost, next);
        }
    }

    printf("-1");

    return 0;
}