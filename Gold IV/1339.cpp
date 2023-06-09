/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int N;
    scanf("%lld", &N);
    int dp[30] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        char str[10];
        scanf("%s", str);
        int len = strlen(str);

        for (int j = 0; j < len; j++)
        {
            dp[str[j] - 'A'] += (int)pow(10, len - j - 1);
        }
    }

    sort(dp, dp + 30, greater<int>());

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[i] * (9 - i);

    printf("%lld", ans);

    return 0;
}