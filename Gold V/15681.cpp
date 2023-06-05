/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf("[debug] ");
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, R, Q;
vector<vector<int>> init_graph;
vector<int> dp;
vector<char> visited;

void dfs(int now)
{
    visited[now] = true;
    for (auto next : init_graph[now])
    {
        if (visited[next])
            continue;
        dfs(next);
        dp[now] += dp[next];
    }
}

signed main()
{
    scanf("%lld %lld %ldd", &N, &R, &Q);
    init_graph.resize(N + 1);
    dp.resize(N + 1, 1);
    visited.resize(N + 1, false);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        init_graph[u].emplace_back(v);
        init_graph[v].emplace_back(u);
    }

    dfs(R);

    while (Q--)
    {
        int u, ans = 0;
        scanf("%lld", &u);

        printf("%lld\n", dp[u]);
    }

    return 0;
}