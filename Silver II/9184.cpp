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

int DP[102][102][102];

void set_DP(int a, int b, int c, int value)
{
    DP[a + 50][b + 50][c + 50] = value;
}

int get_DP(int a, int b, int c)
{
    return DP[a + 50][b + 50][c + 50];
}

int w(int a, int b, int c)
{
    if (get_DP(a, b, c) == 0)
    {
        if (a <= 0 || b <= 0 || c <= 0)
            set_DP(a, b, c, 1);

        else if (a > 20 || b > 20 || c > 20)
            set_DP(a, b, c, w(20, 20, 20));

        else if (a < b && b < c)
            set_DP(a, b, c, w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));

        else
            set_DP(a, b, c, w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
    }
    return get_DP(a, b, c);
}

signed main()
{
    while (true)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}