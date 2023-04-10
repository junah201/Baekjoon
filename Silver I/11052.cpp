/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, DP[1002];

int main()
{
    scanf("%d", &N);
    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%d", &DP[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
        }
    }

    printf("%d", DP[N]);

    return 0;
}