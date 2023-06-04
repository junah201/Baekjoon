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

int N, K, Q, S, E;

vector<vector<tuple<int, int, int>>> graph;
vector<vector<pair<int, int>>> root_graph;
vector<int> deep;

void calc_deep(int now, int cnt, int prev, int cost)
{
    deep[now] = cnt;
    graph[now][1] = {prev, cost, cost};
    for (auto [next, next_cost] : root_graph[now])
    {
        if (deep[next])
            continue;
        calc_deep(next, cnt + 1, now, next_cost);
    }
}

signed main()
{
    scanf("%lld", &N);
    K = std::ceil(std::log2(N));

    graph.clear();
    graph.resize(N + 1, vector<tuple<int, int, int>>(K + 1, {1, INT_MAX, INT_MIN}));

    root_graph.clear();
    root_graph.resize(N + 1);

    deep.clear();
    deep.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        root_graph[u].emplace_back(v, c);
        root_graph[v].emplace_back(u, c);
    }

    int root = 1;

    calc_deep(root, 1, root, 0);
    graph[1][1] = {1, INT_MAX, INT_MIN};

    for (int jump = 2; jump <= K; jump++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            auto [idx1, min1, max1] = graph[i][jump - 1];
            auto [idx2, min2, max2] = graph[idx1][jump - 1];

            graph[i][jump] = {
                idx2,
                min(min1, min2),
                max(max1, max2)};
        }
    }

    scanf("%lld", &Q);

    while (Q--)
    {
        scanf("%lld %lld", &S, &E);
        if (S == E)
        {
            printf("%lld %lld\n", 0, 0);
            continue;
        }

        // 높이 맞추기
        if (deep[S] > deep[E])
            swap(S, E);

        dprintf("%lld %lld\n", S, E);

        int min_ans = INT_MAX, max_ans = INT_MIN;

        while (deep[E] > deep[S])
        {
            for (int i = K; i >= 1; i--)
            {
                auto [idx, min_cost, max_cost] = graph[E][i];
                if (deep[idx] < deep[S])
                    continue;
                min_ans = min(min_ans, min_cost);
                max_ans = max(max_ans, max_cost);
                E = idx;
            }
        }

        if (S == E)
        {
            printf("%lld %lld\n", min_ans, max_ans);
            continue;
        }

        // 공통 조상 찾기
        for (int jump = K; jump >= 1; jump--)
        {
            auto [idx1, min1, max1] = graph[S][jump];
            auto [idx2, min2, max2] = graph[E][jump];
            if (idx1 != idx2)
            {
                min_ans = min({min_ans, min1, min2});
                max_ans = max({max_ans, max1, max2});
                S = idx1;
                E = idx2;
            }
        }

        if (S != E)
        {
            auto [idx1, min1, max1] = graph[S][1];
            auto [idx2, min2, max2] = graph[E][1];

            min_ans = min({min_ans, min1, min2});
            max_ans = max({max_ans, max1, max2});
        }

        printf("%lld %lld\n", min_ans, max_ans);
    }

    return 0;
}