/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, Q;
vector<int> DP(100001, -1);
vector<int> DP2(100001, -1);

int get(int num)
{
    if (DP2[num] == -1)
    {
        int result = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i != 0)
                continue;
            if (i != 1)
            {
                result += get(num / i);
            }
            if (i * i != num)
            {
                result += get(num / (num / i));
            }
        }
        DP2[num] = result;
    }
    return DP2[num];
}

signed main()
{
    DP2[1] = 1;
    scanf("%lld", &N);
    vector<int> stick(100001, 0);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%lld", &tmp);
        stick[tmp]++;
    }

    for (int i = 1; i <= 100000; i++)
    {
        get(i);
    }

    scanf("%lld", &Q);
    for (int i = 0; i < Q; i++)
    {
        int target;
        scanf("%lld", &target);

        if (DP[target] == -1)
        {
            int result = 0;
            for (int j = 1; j * j <= target; j++)
            {
                if (target % j != 0)
                    continue;

                result += DP2[target / j] * stick[j];

                if (j * j != target)
                {
                    int row = target / j;
                    result += DP2[target / row] * stick[row];
                }
            }
            DP[target] = result;
        }
        printf("%lld ", DP[target]);
    }
    return 0;
}