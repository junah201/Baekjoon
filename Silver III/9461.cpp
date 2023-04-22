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
vector<int> DP(102, -1);

int get(int idx)
{
    if (idx <= 0)
        return 0;
    if (idx <= 3)
        return 1;
    if (idx <= 5)
        return 2;

    if (DP[idx] == -1)
        DP[idx] = get(idx - 1) + get(idx - 5);

    return DP[idx];
}

signed main()
{
    scanf("%lld", &N);
    while (N--)
    {
        int K;
        scanf("%lld", &K);
        printf("%lld\n", get(K));
    }
    return 0;
}