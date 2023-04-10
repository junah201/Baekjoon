/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, K;
int mod = 1000000000;
int DP[202][202];

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N; i++)
    {
        DP[1][i] = 1;
    }

    for (int tmp_k = 2; tmp_k <= K; tmp_k++)
    {
        for (int tmp_sum = 0; tmp_sum <= N; tmp_sum++)
        {
            for (int i = 0; i <= N; i++)
            {
                if (tmp_sum + i > N)
                    continue;
                DP[tmp_k][tmp_sum + i] += DP[tmp_k - 1][tmp_sum];
                DP[tmp_k][tmp_sum + i] %= mod;
            }
        }
    }

    printf("%d", DP[K][N] % mod);

    return 0;
}