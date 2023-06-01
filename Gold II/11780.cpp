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

int N, M;
vector<vector<pair<int, vector<int>>>> graph;

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1, vector<pair<int, vector<int>>>(N + 1, {INT_MAX, vector<int>(0)}));

    for (int i = 0; i <= N; i++)
        graph[i][i].first = INT_MAX;

    while (M--)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        graph[a][b].first = min(graph[a][b].first, c);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                graph[i][j].second = {};
            }
            graph[i][j].second = {i, j};
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                {
                    graph[i][j].first = 0;
                    graph[i][j].second = {};
                }
                else if (i == k)
                {
                    graph[i][k].first = 0;
                    graph[i][k].second = {};
                }
                else if (k == j)
                {
                    graph[k][j].first = 0;
                    graph[k][j].second = {};
                }
                else if (graph[i][j].first > graph[i][k].first + graph[k][j].first)
                {
                    graph[i][j].first = graph[i][k].first + graph[k][j].first;
                    graph[i][j].second = {};

                    for (auto node : graph[i][k].second)
                        graph[i][j].second.emplace_back(node);

                    for (size_t idx = 1; idx < graph[k][j].second.size(); idx++)
                    {
                        graph[i][j].second.emplace_back(graph[k][j].second[idx]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j].first == INT_MAX)
                printf("0 ");
            else
                printf("%lld ", graph[i][j].first);
        }
        printf("\n");
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j].second.size() == 0 || graph[i][j].first == INT_MAX)
                printf("0");
            else
            {
                printf("%lld ", graph[i][j].second.size());
                for (auto node : graph[i][j].second)
                    printf("%lld ", node);
            }
            printf("\n");
        }
    }

    return 0;
}