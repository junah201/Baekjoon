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
vector<int> A;

signed main()
{
    scanf("%lld %lld", &N, &M);
    A.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        A[i] = i;
    }

    while (M--)
    {
        int I, J, tmp;
        scanf("%lld %lld", &I, &J);
        tmp = A[I];
        A[I] = A[J];
        A[J] = tmp;
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%lld ", A[i]);
    }

    return 0;
}