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

int a, b, c, d, e, f;

signed main()
{
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);

    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            if ((a * x + b * y) == c && (d * x + e * y) == f)
            {
                printf("%lld %lld", x, y);
                return 0;
            }
        }
    }
    printf("-1 -1");
    return 0;
}