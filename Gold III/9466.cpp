// 9466 텀 프로젝트

#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> graph;
vector<int> visited;
vector<int> is_cycle;

bool dfs(int idx, int cnt)
{
    if (visited[idx] == cnt)
    {
        is_cycle[idx] = 1;
        return true;
    }
    else if (visited[idx] != 0)
        return false;
    visited[idx] = cnt;
    auto res = dfs(graph[idx], cnt);
    if (res && !is_cycle[idx])
    {
        is_cycle[idx] = 1;
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        graph.clear();
        visited.clear();
        is_cycle.clear();
        scanf("%d", &N);
        graph.resize(N + 1);
        visited.resize(N + 1, 0);
        is_cycle.resize(N + 1, 0);
        for (int i = 1; i <= N; i++)
            scanf("%d", &graph[i]);

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, i);
            }
        }
        int ans = N;
        for (int i = 1; i <= N; i++)
            if (is_cycle[i] == 1)
                ans--;
        printf("%d\n", ans);
    }
}