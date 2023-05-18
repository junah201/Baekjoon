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

int N, f[50], cnt1, cnt2;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        cnt1++;
        return 1;
    }
    else
        return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    for (int i = 3; i <= n; i++)
    {
        cnt2++;
    }
    return f[n];
}

signed main()
{
    scanf("%lld", &N);

    cnt1 = 0, cnt2 = 0;
    fib(N);
    fibonacci(N);
    printf("%lld %lld\n", cnt1, cnt2);

    return 0;
}