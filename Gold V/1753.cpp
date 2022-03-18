// 1753 최단경로
// https://www.acmicpc.net/source/40644032

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int next;
    int distance;
};

int N, E, S;
vector<vector<info>> v;
vector<int> cost;

struct block
{
    int idx, dis;
};

priority_queue<pair<int, int>> q;

void bfs()
{
    cost[S] = 0;
    q.push({0, S});
    while (!q.empty())
    {
        auto [dis, cur] = q.top();
        dis = -dis;
        q.pop();

        if (dis > cost[cur])
            continue;

        for (auto [i, d] : v[cur])
        {
            if (dis + d < cost[i])
            {
                cost[i] = dis + d;
                q.push({-cost[i], i});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &E);
    v.resize(N + 1);
    cost.resize(N + 1, INT_MAX);
    scanf("%d", &S);
    for (int i = 0, a, b, c; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }

    bfs();

    for (int i = 1; i <= N; i++)
        if (cost[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", cost[i]);

    return 0;
}