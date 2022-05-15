#include <bits/stdc++.h>
using namespace std;

int V, ans_cur, ans_dis;
vector<vector<pair<int, int>>> graph;
vector<int> visited;

int dfs(int idx, int dis)
{
    if (visited[idx] < dis)
        return 0;
    visited[idx] = dis;
    if (ans_dis < visited[idx])
    {
        ans_cur = idx;
        ans_dis = visited[idx];
    }
    for (auto i : graph[idx])
    {
        int tcur = i.first;
        int tdis = i.second;
        dfs(tcur, dis + tdis);
    }
    return 0;
}

int main()
{
    scanf("%d", &V);
    graph.resize(V + 1);
    visited.resize(V + 1, INT_MAX);
    for (int i = 1, start, end, dis; i < V; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        graph[start].push_back({end, dis});
        graph[end].push_back({start, dis});
    }
    dfs(1, 0);
    visited.resize(0);
    visited.resize(V + 1, INT_MAX);
    dfs(ans_cur, 0);
    printf("%d", ans_dis);
    return 0;
}