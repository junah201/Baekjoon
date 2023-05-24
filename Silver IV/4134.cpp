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

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

signed main()
{
    scanf("%lld", &T);

    while (T--)
    {
        scanf("%lld", &N);

        for (int i = N;; i++)
        {
            if (is_prime(i))
            {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}