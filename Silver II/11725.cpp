/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> ans;

int main()
{
    scanf("%d", &N);
    graph.resize(N + 2);
    ans.resize(N + 2, -1);

    for (int i = 1, a, b; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    queue<tuple<int, int>> q;
    q.emplace(1, 1);
    ans[1] = 1;

    while (!q.empty())
    {
        auto [idx, per] = q.front();
        q.pop();

        for (auto i : graph[idx])
        {
            if (ans[i] != -1)
                continue;

            ans[i] = idx;
            q.emplace(i, idx);
        }
    }

    for (int i = 2; i <= N; i++)
        printf("%d\n", ans[i]);

    return 0;
}