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

int A, B;

signed main()
{
    scanf("%lld", &A);
    scanf("%lld", &B);

    printf("%lld", A * B);
    return 0;
}

대충 나중에 스트릭 용도라는 뜻