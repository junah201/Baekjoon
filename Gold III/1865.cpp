#include <bits/stdc++.h>
using namespace std;

int T;

int solve()
{
    int N, M, W;
    vector<vector<pair<int, int>>> graph;
    vector<tuple<int, int, int>> edges;
    scanf("%d %d %d", &N, &M, &W);
    for (int i = 0, start, end, dis; i < M; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        // graph.push_back({start, end, dis});
        edges.emplace_back(start, end, dis);
    }
    for (int i = 0, start, end, dis; i < W; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        // graph.push_back({start, end, -dis});
        edges.emplace_back(start, end, -dis);
    }

    vector<int> dist(N + 1, INT_MAX);
    dist.resize(N + 1, INT32_MAX);
    dist[1] = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        for (auto [start, end, dis] : edges)
        {
            if (dist[start] != INT_MAX && dist[end] > dist[start] + dis)
                if (i != N - 1)
                    break;
            dist[end] = dist[start] + dis;
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d %d\n", i, dist[i]);
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
}