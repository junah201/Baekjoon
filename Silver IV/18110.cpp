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
vector<int> A;

signed main()
{
    scanf("%lld", &N);
    A.resize(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    sort(A.begin(), A.end());

    int tmp = round(0.15 * N);

    int result = 0;
    for (int i = tmp; i < N - tmp; i++)
        result += A[i];

    printf("%d", (int)round((result * 1.0) / (N - tmp - tmp)));

    return 0;
}