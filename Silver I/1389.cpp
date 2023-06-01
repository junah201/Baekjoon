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
int ans1 = 0, ans2 = INT_MAX;
vector<vector<int>> graph;

signed main()
{
    scanf("%lld %lld", &N, &M);
    graph.resize(N + 1, vector<int>(N + 1, INT_MAX));

    for (int i = 0; i <= N; i++)
        graph[i][i] = 0;

    while (M--)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int tmp_sum = 0;
        for (int j = 1; j <= N; j++)
            tmp_sum += graph[i][j];

        if (ans2 > tmp_sum)
        {
            ans1 = i;
            ans2 = tmp_sum;
        }
    }

    printf("%lld", ans1);

    return 0;
}