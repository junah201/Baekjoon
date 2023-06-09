/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int DP[100001 * 50000];

void set_DP(int idx, int value)
{
    if (idx > 100001)
        return;
    DP[idx] = value;
}

int get_DP(int idx)
{
    if (idx > 100000)
        return 0;
    return DP[idx];
}

signed main()
{
    int N, sum;
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        sum += A[i];
    }
    sort(A.begin(), A.end());

    set_DP(0, -1);

    for (int idx = 0; idx < N; idx++)
    {
        for (int i = -sum; i <= sum; i++)
        {
            if (get_DP(i) < idx + 1 && get_DP(i))
            {
                if (get_DP(i + A[idx]) == 0)
                    set_DP(i + A[idx], idx + 1);
            }
        }
    }

    for (int i = 1; i <= sum; i++)
    {
        if (get_DP(i) == 0)
        {
            printf("%lld", i);
            return 0;
        }
    }

    printf("%lld", sum + 1);

    return 0;
}