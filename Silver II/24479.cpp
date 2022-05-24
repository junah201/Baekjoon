#include <bits/stdc++.h>
using namespace std;

int N, M, R, cnt = 1;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> ans;

void dfs(int idx)
{
    if (visited[idx])
        return;
    visited[idx] = true;

    ans[idx] = cnt++;

    for (auto i : graph[idx])
        dfs(i);
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    graph.resize(N + 1);
    visited.resize(N + 1, false);
    ans.resize(N + 1, 0);
    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
    dfs(R);
    for (int i = 1; i <= N; i++)
        printf("%d\n", ans[i]);
    return 0;
}