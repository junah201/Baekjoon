/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
ll DP[1002][10];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i <= 9; i++)
        DP[1][i] = 1;

    for (int i = 1; i <= N + 1; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i + 1][j] += DP[i][k];
                DP[i + 1][j] %= 10007;
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i <= 9; i++)
    {
        ans += DP[N][i];
        ans %= 10007;
    }

    printf("%lld", ans);

    return 0;
}