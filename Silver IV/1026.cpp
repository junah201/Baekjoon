/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
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

signed main()
{
    int N;
    scanf("%lld", &N);
    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    for (int i = 0; i < N; i++)
        scanf("%lld", &B[i]);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i] * B[i];

    printf("%lld", ans);

    return 0;
}