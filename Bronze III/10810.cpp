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

signed main()
{
    scanf("%lld %lld", &N, &M);
    vector<int> A(N, 0);
    while (M--)
    {
        int I, J, K;
        scanf("%lld %lld %lld", &I, &J, &K);
        for (int idx = I - 1; idx <= J - 1; idx++)
        {
            A[idx] = K;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%lld ", A[i]);
    }
    return 0;
}