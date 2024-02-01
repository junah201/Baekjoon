/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;

signed main()
{
    scanf("%lld", &N);

    vector<int> K(1000002, 0);
    vector<int> sum(1000002, 0);

    for (int i = 0, s, e; i < N; i++)
    {
        scanf("%lld %lld", &s, &e);
        K[s]++;
        K[e + 1]--;
    }

    sum[0] = K[0];
    for (int i = 1; i < 1000001; i++)
    {
        sum[i] = sum[i - 1] + K[i];
    }

    int Q;
    scanf("%lld", &Q);

    while (Q--)
    {
        int t;
        scanf("%lld", &t);

        printf("%lld\n", sum[t]);
    }

    return 0;
}