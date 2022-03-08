// 1325 효율적인 해킹
// https://www.acmicpc.net/source/40148267

#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<vector<int>> graph;
vector<int> ids;
vector<int> visited;

void dfs(int idx, int id)
{
    visited[idx] = 1;
    ids[id]++;
    for (auto i : graph[idx])
    {
        if (visited[i])
            continue;
        dfs(i, id);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 1);
    ids.resize(N + 1, 0);
    visited.resize(N + 1, 0);
    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        visited.resize(0);
        visited.resize(N + 1, 0);
        dfs(i, i);
        ans = max(ans, ids[i]);
    }

    for (int i = 1; i <= N; i++)
        if (ids[i] == ans)
            printf("%d ", i);

    return 0;
}