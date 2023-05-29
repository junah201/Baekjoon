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

int cnt;

signed main()
{
    for (int i = 0, cnt; i < 3; i++)
    {
        cnt = 0;
        for (int j = 0, tmp; j < 4; j++)
        {
            scanf("%lld", &tmp);
            cnt += !tmp;
        }

        if (cnt == 0)
            printf("E\n");
        else
            printf("%c\n", 'A' + cnt - 1);
    }
    return 0;
}