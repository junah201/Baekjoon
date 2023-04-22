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
vector<int> DP(80002, 0);

int get_DP(int idx)
{
    return DP[idx + 40000];
}

void set_DP(int idx, int value)
{
    DP[idx + 40000] = value;
}

signed main()
{
    scanf("%lld", &N);
    vector<int> D(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &D[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (get_DP(D[i]) == 0)
            set_DP(D[i], i + 1);
        if (get_DP(-D[i]) == 0)
            set_DP(-D[i], i + 1);
        for (int j = -40000; j <= 40000; j++)
        {
            if (get_DP(j) == 0 || get_DP(j) == i + 1)
                continue;
            if (j - D[i] >= -40000 && !get_DP(j - D[i]))
                set_DP(j - D[i], i + 1);
            if (j + D[i] <= 40000 && !get_DP(j + D[i]))
                set_DP(j + D[i], i + 1);
        }
    }

    for (int i = 1; i <= 15; i++)
        dprintf("%lld ", get_DP(i));
    dprintf("\n");

    scanf("%lld", &M);
    for (int i = 0; i < M; i++)
    {
        int target;
        scanf("%lld", &target);
        if (get_DP(target))
            printf("Y ");
        else
            printf("N ");
    }
    return 0;
}