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

int N, ans, remove_node, root;
vector<vector<int>> graph;

void dfs(int node)
{
    if (graph[node].empty() || (graph[node].size() == 1 && graph[node][0] == remove_node))
    {
        ans++;
        return;
    }

    for (auto next : graph[node])
    {
        if (next == remove_node)
            continue;
        dfs(next);
    }
}

signed main()
{
    scanf("%lld", &N);
    graph.resize(N);
    for (int i = 0; i < N; i++)
    {
        int prev;
        scanf("%lld", &prev);

        if (prev == -1)
        {
            root = i;
            continue;
        }

        graph[prev].emplace_back(i);
    }

    scanf("%lld", &remove_node);

    if (remove_node == root)
    {
        printf("0");
        return 0;
    }

    dfs(root);

    printf("%lld", ans);

    return 0;
}