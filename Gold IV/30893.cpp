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

int N, S, E;
vector<vector<int>> graph;
vector<int> visited;

signed main()
{
    scanf("%lld %lld %lld", &N, &S, &E);
    graph.resize(N + 1);
    visited.resize(N + 1, -1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    queue<pair<int, int>> q;
    visited[S] = 0;
    q.emplace(S, 0);

    int total_cnt = -1;

    while (!q.empty())
    {
        auto [now, cnt] = q.front();
        q.pop();

        for (auto i : graph[now])
        {
            if (visited[i] != -1)
                continue;

            visited[i] = now;
            q.emplace(i, cnt + 1);

            if (i == E)
            {
                total_cnt = cnt + 1;
                break;
            }
        }
    }

    int now = visited[E];
    int cnt = total_cnt - 1;
    while (cnt)
    {
        // printf("now:%lld cnt:%lld, size:%lld\n", now, cnt, graph[now].size());
        if (cnt % 2 == 1)
        {
            if (graph[now].size() > 2)
            {
                printf("Second");
                return 0;
            }
        }
        now = visited[now];
        cnt--;
    }

    printf("First");

    return 0;
}