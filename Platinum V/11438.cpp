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

int T, N, K, Q;
vector<vector<int>> graph;
vector<vector<int>> root_graph;
vector<int> deep;

void calc_deep(int now, int cnt, int prev)
{
    deep[now] = cnt;
    graph[now][1] = prev;
    for (int next : root_graph[now])
    {
        if (deep[next])
            continue;
        calc_deep(next, cnt + 1, now);
    }
}

signed main()
{
    scanf("%lld", &N);
    K = std::ceil(std::log2(N));

    graph.clear();
    graph.resize(N + 1, vector<int>(K + 1, 1));
    root_graph.clear();
    root_graph.resize(N + 1);
    deep.clear();
    deep.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        root_graph[u].emplace_back(v);
        root_graph[v].emplace_back(u);
    }

    int S, E;

    calc_deep(1, 1, 1);
    dprintf("==== deep ====\n");
    for (int i = 1; i <= N; i++)
    {
        dprintf("%lld :%lld\n", i, deep[i]);
    }

    for (int jump = 2; jump <= K; jump++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            int prev1 = graph[i][jump - 1];
            graph[i][jump] = graph[prev1][jump - 1];
        }
    }

    scanf("%lld", &Q);
    dprintf("Q:%lld\n", Q);
    while (Q--)
    {
        scanf("%lld %lld", &S, &E);
        // 높이 맞추기
        int tmp = E;
        if (deep[S] > deep[E])
            swap(S, E);

        dprintf("%lld %lld\n", S, E);

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
        {
            printf("%lld\n", S);
            continue;
        }

        // 공통 조상 찾기

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

        printf("%lld\n", ans);
    }

    return 0;
}