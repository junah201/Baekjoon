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

int V, E;
vector<vector<int>> graph;
vector<int> id, visited;
bool result;
int cnt = 1;
vector<char> is_cut_vertax;

int dfs1(int now, bool is_root)
{
    id[now] = cnt++;
    int ret = id[now];
    int child = 0;

    for (int next : graph[now])
    {
        if (id[next])
        {
            ret = min(ret, id[next]);
            continue;
        }

        child++;

        int low = dfs1(next, false);

        if (!is_root && low >= id[now])
        {
            is_cut_vertax[now] = true;
        }

        ret = min(ret, low);
    }

    if (is_root && child >= 2)
    {
        is_cut_vertax[now] = true;
    }

    return ret;
}

signed main()
{
    scanf("%lld %lld", &V, &E);
    graph.resize(V + 1);
    is_cut_vertax.resize(V + 1, false);
    id.resize(V + 1, 0);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int i = 1; i <= V; i++)
    {
        if (id[i] == 0)
        {
            dfs1(i, true);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= V; i++)
    {
        if (is_cut_vertax[i])
            cnt++;
    }

    printf("%lld\n", cnt);
    for (int i = 1; i <= V; i++)
    {
        if (is_cut_vertax[i])
            printf("%lld ", i);
    }
}