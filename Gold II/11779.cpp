/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M, start_node, end_node, ans = INT_MAX;
vector<vector<pair<int, int>>> graph;
vector<int> visited;
vector<int> pre;

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 2);
    visited.resize(N + 2, INT_MAX);
    pre.resize(N + 2);

    for (int i = 0, a, b, cost; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &cost);
        graph[a].emplace_back(cost, b);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    scanf("%d %d", &start_node, &end_node);

    priority_queue<pair<int, int>> q;

    q.emplace(0, start_node);

    while (!q.empty())
    {
        auto [total_cost, idx] = q.top();
        q.pop();

        total_cost = -total_cost;

        for (auto [next_cost, next_idx] : graph[idx])
        {
            if (visited[next_idx] <= total_cost + next_cost)
                continue;

            visited[next_idx] = total_cost + next_cost;

            if (total_cost + next_cost >= ans)
                continue;
            pre[next_idx] = idx;
            if (next_idx == end_node)
                ans = min(ans, total_cost + next_cost);
            q.emplace(-(total_cost + next_cost), next_idx);
        }
    }

    printf("%d\n", ans);
    stack<int> tmp;
    int tmp_idx = end_node;
    while (1)
    {
        tmp.emplace(tmp_idx);

        if (tmp_idx == start_node)
            break;
        tmp_idx = pre[tmp_idx];
    }

    printf("%ld\n", tmp.size());
    while (!tmp.empty())
    {
        printf("%d ", tmp.top());
        tmp.pop();
    }

    return 0;
}