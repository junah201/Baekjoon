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
vector<vector<pair<int, int>>> init_graph;
vector<vector<pair<int, int>>> graph;
vector<int> deep, bits;

void cula_deep(int now, int prev, int cost, int deep_cnt)
{
    graph[now][1] = {prev, cost};
    deep[now] = deep_cnt;
    for (auto [next, next_cost] : init_graph[now])
    {
        if (graph[next][1].second)
            continue;

        cula_deep(next, now, next_cost, deep_cnt + 1);
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
            if (deep[graph[E][i].first] < deep[S])
                continue;
            E = graph[E][i].first;
        }
    }

    if (S == E)
        return S;

    int root = 1;
    int ans = root;

    for (int jump = K; jump >= 1; jump--)
    {
        if (graph[S][jump].first != graph[E][jump].first)
        {
            S = graph[S][jump].first;
            E = graph[E][jump].first;
        }
    }

    if (S == E)
        ans = S;
    else
        ans = graph[S][1].first;

    return ans;
}

int get_dist(int S, int E)
{
    if (S == E)
        return 0;

    int result = 0;

    for (int jump = K; jump >= 1; jump--)
    {
        auto [idx, cost] = graph[S][jump];
        if (deep[idx] > deep[E])
        {
            dprintf("=%lld %lld\n", jump, idx);
            result += bits[jump];
            S = idx;
        }
    }

    return result + 1;
}

int get_nth_node(int start, int nth)
{
    if (nth == 0)
        return start;

    int cnt = 0;
    for (int jump = K; jump >= 1; jump--)
    {
        auto [idx, cost] = graph[start][jump];
        if (cnt + bits[jump] < nth)
        {
            start = idx;
            cnt += bits[jump];
        }
    }
    cnt += 1;
    start = graph[start][1].first;

    return start;
}

signed main()
{
    int root = 1;
    scanf("%lld", &N);
    K = ceil(log2(N));

    bits.resize(K + 1);

    for (int i = 1; i <= K; i++)
        bits[i] = 1 << (i - 1);

    graph.resize(N + 1, vector<pair<int, int>>(K + 1, {1, 0}));
    deep.resize(N + 1, false);
    init_graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        init_graph[u].emplace_back(v, w);
        init_graph[v].emplace_back(u, w);
    }

    cula_deep(root, root, INT_MAX, 1);
    deep[1] = 1;
    graph[1][1] = {1, 0};

    for (int jump = 2; jump <= K; jump++)
    {
        for (int i = 1; i <= N; i++)
        {
            auto [idx1, cost1] = graph[i][jump - 1];
            auto [idx2, cost2] = graph[idx1][jump - 1];
            graph[i][jump] = {idx2, cost1 + cost2};
        }
    }

    scanf("%lld", &M);
    while (M--)
    {
        int oper, u, v, k;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            scanf("%lld %lld", &u, &v);

            if (u == v)
            {
                printf("%lld\n", 0);
                continue;
            }

            // 높이 맞추기
            if (deep[u] < deep[v])
                swap(u, v);

            int ans = 0;

            while (deep[u] > deep[v])
            {
                for (int i = K; i >= 1; i--)
                {
                    auto [idx, cost] = graph[u][i];
                    if (deep[idx] < deep[v])
                        continue;

                    ans += cost;
                    u = idx;
                }
            }

            if (u == v)
            {
                printf("%lld\n", ans);
                continue;
            }

            for (int jump = K; jump >= 1; jump--)
            {
                auto [idx1, cost1] = graph[u][jump];
                auto [idx2, cost2] = graph[v][jump];

                if (idx1 != idx2)
                {
                    ans += cost1 + cost2;
                    u = idx1;
                    v = idx2;
                }
            }

            if (u != v)
            {
                auto [idx1, cost1] = graph[u][1];
                auto [idx2, cost2] = graph[v][1];

                ans += cost1 + cost2;
            }

            printf("%lld\n", ans);
        }
        else if (oper == 2)
        {
            scanf("%lld %lld %lld", &u, &v, &k);
            int lca = get_lca(u, v);
            int cnt_u = get_dist(u, lca);
            int cnt_v = get_dist(v, lca);
            k -= 1;

            if (cnt_u > k)
                printf("%lld\n", get_nth_node(u, k));
            else
                printf("%lld\n", get_nth_node(v, cnt_u + cnt_v - k));
        }
    }

    return 0;
}