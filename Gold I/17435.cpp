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

int N, K, Q;
vector<vector<int>> graph;
vector<int> bits;

signed main()
{
    scanf("%lld", &N);
    K = std::ceil(std::log2(500001));

    bits.resize(K + 1);
    for (int i = 1; i <= K; i++)
    {
        bits[i] = 1 << (i - 1);
    }

    graph.clear();
    graph.resize(N + 1, vector<int>(K + 1, -1));

    for (int i = 1; i <= N; i++)
    {
        int u;
        scanf("%lld", &u);
        graph[i][1] = u;
    }

    for (int jump = 2; jump <= K; jump++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            int prev1 = graph[i][jump - 1];
            graph[i][jump] = graph[prev1][jump - 1];
        }
    }
    scanf("%lld", &Q);

    while (Q--)
    {
        int n, x;
        scanf("%lld %lld", &n, &x);

        for (int jump = K; jump >= 1 && n != 0; jump--)
        {
            if (n >= bits[jump])
            {
                n -= bits[jump];
                x = graph[x][jump];
            }
        }
        printf("%lld\n", x);
    }

    return 0;
}