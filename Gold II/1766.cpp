// 1766 문제집
// https://www.acmicpc.net/source/40428420

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> edge_cnt;

struct cmp
{
    bool operator()(int a, int b)
    {
        if (edge_cnt[a] == edge_cnt[b])
            return a > b;
        return edge_cnt[a] > edge_cnt[b];
    }
};

int main()
{
    scanf("%d %d", &N, &M);
    graph.resize(N + 1);
    edge_cnt.resize(N + 1);
    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        edge_cnt[b]++;
    }

    priority_queue<int, vector<int>, cmp> q;

    for (int i = 1; i <= N; i++)
        if (!edge_cnt[i])
            q.emplace(i);

    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        printf("%d ", cur);

        for (auto i : graph[cur])
        {
            edge_cnt[i]--;
            if (!edge_cnt[i])
                q.emplace(i);
        }
    }
    return 0;
}