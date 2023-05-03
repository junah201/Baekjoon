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
int DP[1000002];
int mod = 1000000009;

signed main()
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i <= 1000000; i++)
    {
        DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
        DP[i] %= mod;
    }

    scanf("%lld", &N);
    while (N--)
    {
        int tmp;
        scanf("%lld", &tmp);
        printf("%lld\n", DP[tmp]);
    }
    return 0;
}