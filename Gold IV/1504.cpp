#include <bits/stdc++.h>
using namespace std;

struct info
{
    int next;
    int distance;
};

int N, E, A, B;
vector<vector<info>> v;

struct block
{
    int idx, dis;
};

priority_queue<pair<int, int>> q;

int bfs(int start, int end)
{
    vector<int> cost;
    cost.resize(N + 1, INT_MAX);
    cost[start] = 0;
    q.push({0, start});
    while (!q.empty())
    {
        auto [dis, cur] = q.top();
        dis = -dis;
        q.pop();

        if (dis > cost[cur])
            continue;

        if (cur == end)
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
    if (cost[end] == INT_MAX)
        return -1;
    return cost[end];
}

int main()
{
    scanf("%d %d", &N, &E);
    v.resize(N + 1);
    for (int i = 0, a, b, c; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    scanf("%d %d", &A, &B);

    int AB = bfs(A, B);
    int A1 = bfs(A, 1);
    int B1 = bfs(B, 1);
    int AN = bfs(A, N);
    int BN = bfs(B, N);

    if (min(AB, min(A1, min(B1, min(AN, BN)))) == -1)
    {
        printf("%d", -1);
        return 0;
    }

    int ans = bfs(A, B) + min(bfs(1, A) + bfs(B, N), bfs(1, B) + bfs(A, N));

    printf("%d", ans);

    return 0;
}