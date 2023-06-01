/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;
vector<vector<int>> graph;
vector<vector<int>> is_connet;
priority_queue<tuple<int, int, int>> pq;

signed main()
{
    scanf("%lld", &N);
    graph.resize(N, vector<int>(N));
    is_connet.resize(N, vector<int>(N, INT_MAX));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &graph[y][x]);
        }
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = y + 1; x < N; x++)
        {
            pq.emplace(graph[y][x], x, y);
        }
    }

    while (!pq.empty())
    {
        auto [value, x, y] = pq.top();
        pq.pop();
    }

    return 0;
}