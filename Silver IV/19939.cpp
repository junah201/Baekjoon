/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int N, K;
    scanf("%lld %lld", &N, &K);

    for (int i = 1; i <= K; i++)
    {
        N -= i;
        if (N < 0)
        {
            printf("-1");
            return 0;
        }
    }

    if (N == 0)
    {
        printf("%lld", K - 1);
    }
    else
    {
        if (N % K == 0)
        {
            printf("%lld", K - 1);
        }
        else
        {
            printf("%lld", K);
        }
    }

    return 0;
}