/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int T;

void solve()
{
    int N, M;
    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
    }
    printf("%lld\n", N - 1);
}

signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}
