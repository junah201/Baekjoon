#include <bits/stdc++.h>
using namespace std;

int N;
int max_dis, max_idx;
int k1, k2;
vector<vector<pair<int, int>>> graph;
vector<int> visited;
vector<int> dis1, dis2;

int dfs(int idx, int dis)
{
    if (visited[idx] < dis)
        return 0;
    visited[idx] = dis;
    if (max_dis < visited[idx])
    {
        max_idx = idx;
        max_dis = visited[idx];
    }
    for (auto i : graph[idx])
    {
        dfs(i.first, dis + i.second);
    }
    return 0;
}

int get_dis1(int idx, int dis)
{
    if (dis > dis1[idx])
        return 0;
    dis1[idx] = min(dis, dis1[idx]);
    for (auto i : graph[idx])
        get_dis1(i.first, dis + i.second);
    return 0;
}
int get_dis2(int idx, int dis)
{
    if (dis > dis2[idx])
        return 0;
    dis2[idx] = min(dis, dis2[idx]);
    for (auto i : graph[idx])
        get_dis2(i.first, dis + i.second);
    return 0;
}

int main()
{
    // 입력
    scanf("%d", &N);
    graph.resize(N + 1);
    visited.resize(N + 1, INT_MAX);
    for (int i = 0, start, end, dis; i < N - 1; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        graph[start].push_back({end, dis});
        graph[end].push_back({start, dis});
    }
    dfs(1, 0);
    k1 = max_idx;
    visited.erase(visited.begin(), visited.end());
    visited.resize(N + 1, INT_MAX);

    max_dis = 0;
    dfs(k1, 0);

    k2 = max_idx;

    dis1.erase(dis1.begin(), dis1.end());
    dis1.resize(N + 1, INT_MAX);
    get_dis1(k1, 0);
    dis2.erase(dis2.begin(), dis2.end());
    dis2.resize(N + 1, INT_MAX);
    get_dis2(k2, 0);
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", max(dis1[i], dis2[i]));
    }
    return 0;
}