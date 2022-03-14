// 1005 ACM Craft
// https://www.acmicpc.net/source/40439050

#include <bits/stdc++.h>
using namespace std;

int T, N, K, W, ans;
vector<vector<int>> graph;
vector<int> edge_cnt;
vector<int> cost;
vector<int> DP;

struct cmp
{
    bool operator()(int a, int b)
    {
        return edge_cnt[a] > edge_cnt[b];
    }
};

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &K);
        cost.resize(0);
        cost.resize(N + 1, 0);
        graph.resize(0);
        graph.resize(N + 1);
        edge_cnt.resize(0);
        edge_cnt.resize(N + 1, 0);
        DP.resize(0);
        DP.resize(N + 1, 0);
        for (int i = 1; i <= N; i++)
            scanf("%d", &cost[i]);
        for (int i = 0, a, b; i < K; i++)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            edge_cnt[b]++;
        }
        scanf("%d", &W);

        queue<int> q;

        for (int i = 1; i <= N; i++)
            if (!edge_cnt[i])
            {
                q.emplace(i);
                DP[i] = cost[i];
            }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            if (cur == W)
                break;

            for (auto i : graph[cur])
            {
                edge_cnt[i]--;
                DP[i] = max(DP[i], DP[cur] + cost[i]);
                if (!edge_cnt[i])
                    q.push(i);
            }
        }
        printf("%d\n", DP[W]);
    }
    return 0;
}