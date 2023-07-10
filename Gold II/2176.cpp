/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

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
int ans;
vector<vector<pair<int, int>>> graph;
vector<int> dist, dist2, dp;

void dfs(int now)
{
    if (now == 2)
        ans++;

    for (auto [next, cost] : graph[now])
    {
        if (dist[next] < dist[now])
        {
            dfs(next);
        }
    }
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1);
    dist.resize(N + 1, INF);
    dist2.resize(N + 1, INF);
    dp.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int S = 1, T = 2;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, T);
    dist[T] = 0;

    dp[2] = 1;
    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (cost > dist[now])
            continue;

        for (auto [next, ncost] : graph[now])
        {
            if (cost + ncost < dist[next])
            {
                dist[next] = cost + ncost;
                pq.emplace(cost + ncost, next);
            }

            if (cost > dist[next])
            {
                dp[now] += dp[next];
            }
        }
    }

    printf("%lld", dp[1]);

    return 0;
}