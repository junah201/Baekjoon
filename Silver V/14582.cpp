/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
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

int K[2][9];

signed main()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0, tmp; j < 9; j++)
        {
            scanf("%lld", &tmp);
            if (i == 0)
            {
                K[i][j] = tmp;
            }
            else
            {
                K[i][j] = K[i][j - 1] + tmp;
            }
        }
    }

    int flag = false; // 재미니스가 이기고 있던 순간이 있었는지
    for (int i = 0; i < 9; i++)
    {
        if (K[0][i] >= K[1][i])
            flag = true;
    }

    if (K[0][8] < K[1][8] && flag == true)
    {
        printf("Yes");
    }
    else
        printf("No");

    return 0;
}
