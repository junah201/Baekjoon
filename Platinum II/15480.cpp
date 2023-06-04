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

int N, M, K;
vector<vector<int>> init_graph;
vector<vector<int>> graph;
vector<int> deep;

void cula_deep(int now, int prev, int deep_cnt)
{
    graph[now][1] = prev;
    deep[now] = deep_cnt;
    for (int next : init_graph[now])
    {
        if (deep[next])
            continue;

        cula_deep(next, now, deep_cnt + 1);
    }
}

int get_lca(int S, int E)
{
    if (deep[S] > deep[E])
        swap(S, E);

    while (deep[E] > deep[S])
    {
        for (int i = K; i >= 1; i--)
        {
            if (deep[graph[E][i]] < deep[S])
                continue;
            E = graph[E][i];
        }
    }

    if (S == E)
        return S;

    int ans = 1;

    for (int jump = K; jump >= 1; jump--)
    {
        if (graph[S][jump] != graph[E][jump])
        {
            S = graph[S][jump];
            E = graph[E][jump];
        }
    }

    if (S == E)
        ans = S;
    else
        ans = graph[S][1];

    return ans;
}

signed main()
{
    int root = 1;
    scanf("%lld", &N);
    K = ceil(log2(N));

    init_graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        init_graph[u].emplace_back(v);
        init_graph[v].emplace_back(u);
    }

    scanf("%lld", &M);

    graph.resize(N + 1, vector<int>(K + 1, 1));
    deep.resize(N + 1, false);

    cula_deep(root, root, 1);
    deep[root] = 1;
    graph[root][1] = root;

    for (int jump = 2; jump <= K; jump++)
    {
        for (int i = 1; i <= N; i++)
        {
            int idx1 = graph[i][jump - 1];
            int idx2 = graph[idx1][jump - 1];
            graph[i][jump] = idx2;
        }
    }

    dprintf("%lld\n", M);
    while (M--)
    {
        int r, u, v;
        scanf("%lld %lld %lld", &r, &u, &v);

        int lca_uv = get_lca(u, v);
        int lca_ur = get_lca(u, r);
        int lca_vr = get_lca(v, r);

        int ans = max({
                          make_pair(deep[lca_uv], lca_uv),
                          make_pair(deep[lca_ur], lca_ur),
                          make_pair(deep[lca_vr], lca_vr),
                      })
                      .second;

        printf("%lld\n", ans);
    }

    return 0;
}