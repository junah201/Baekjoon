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

int T, N;

signed main()
{
    scanf("%lld", &T);

    while (T--)
    {
        scanf("%lld", &N);
        int q = 0, d = 0, n = 0, p = 0;
        while (N >= 25)
        {
            q++;
            N -= 25;
        }
        while (N >= 10)
        {
            d++;
            N -= 10;
        }
        while (N >= 5)
        {
            n++;
            N -= 5;
        }
        while (N >= 1)
        {
            p++;
            N -= 1;
        }
        printf("%lld %lld %lld %lld\n", q, d, n, p);
    }

    return 0;
}