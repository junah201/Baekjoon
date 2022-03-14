// 2252 줄 세우기
// https://www.acmicpc.net/source/40426020

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
bitset<32002> visited;

bool check(int idx)
{
    for (auto i : graph[idx])
        if (!visited[i])
            return false;
    return true;
}

void bfs()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (check(cur) || q.empty())
        {
            visited[cur] = 1;
            printf("%d ", cur);
        }
        else
            q.push(cur);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 1);
    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }
    bfs();
    return 0;
}