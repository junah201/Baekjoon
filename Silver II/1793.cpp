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
vector<int> DP(252, INT_MAX);

signed main()
{
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 3;
    for (int i = 3; i <= 250; i++)
    {
        DP[i] = DP[i - 1] + (2 * DP[i - 2]);
    }
    while (scanf("%lld", &N) != EOF)
    {
        printf("%lld\n", DP[N]);
    }
    return 0;
}