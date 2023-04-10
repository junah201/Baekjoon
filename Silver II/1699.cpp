/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
int DP[100002];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        DP[i] = i;
    }

    for (int i = 1; i * i <= N; i++)
    {
        DP[i * i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j * j < i; j++)
        {
            DP[i] = min(DP[i], DP[i - j * j] + 1);
        }
    }

    printf("%d", DP[N]);

    return 0;
}