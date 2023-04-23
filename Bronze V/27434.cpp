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

int N, ans = 1;

signed main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
        ans *= i;

    printf("%lld", ans);
    return 0;
}