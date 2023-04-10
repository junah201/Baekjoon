/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
ll DP[102][10];
ll mod = 1000000000;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j - 1 >= 0)
            {
                DP[i][j] += DP[i - 1][j - 1];
                DP[i][j] %= mod;
            }
            if (j + 1 < 10)
            {
                DP[i][j] += DP[i - 1][j + 1];
                DP[i][j] %= mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += DP[N][i];
        ans %= mod;
    }

    printf("%lld", ans);

    return 0;
}