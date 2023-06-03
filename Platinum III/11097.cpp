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

int T;

void solve()
{
    int N;
    scanf("%lld", &N);
    vector<vector<int>> graph(N, vector<int>(N));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &graph[y][x]);
            if (x == y)
                graph[y][x] = 0;
        }
    }
}

signed main()
{
    scanf("%lld", &N);
    return 0;
}