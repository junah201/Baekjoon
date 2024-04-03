/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

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
int inp[2002];
vector<vector<int>> DP(2000, vector<int>(2000, -1));

int get(int idx, int sidx, int hidx)
{
    if (idx == N + 1)
        return 0;

    if (DP[sidx][hidx] != -1)
        return DP[sidx][hidx];

    int result = INF;
    int tmp = 0;

    if (sidx != 0)
        tmp = abs(inp[sidx] - inp[idx]);
    result = min(result, get(idx + 1, idx, hidx) + tmp);

    tmp = 0;
    if (hidx != 0)
        tmp = abs(inp[hidx] - inp[idx]);
    result = min(result, get(idx + 1, sidx, idx) + tmp);

    return DP[sidx][hidx] = result;
}

signed main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &inp[i]);
    }

    printf("%lld", get(1, 0, 0));

    return 0;
}