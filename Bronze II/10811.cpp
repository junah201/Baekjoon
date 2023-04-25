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
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        A[i] = i;
    }
    while (M--)
    {
        int a, b, tmp;
        scanf("%lld %lld", &b, &a);
        for (int i = 0; i <= (a - b) / 2; i++)
        {
            tmp = A[b + i];
            A[b + i] = A[a - i];
            A[a - i] = tmp;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%lld ", A[i]);
    }

    return 0;
}