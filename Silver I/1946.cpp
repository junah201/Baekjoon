/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

void solve()
{
    int N;
    scanf("%lld", &N);
    vector<pair<int, int>> A(N);
    vector<int> B(100001, 0), C(100001, 0);
    for (int i = 0; i < N; i++)
        scanf("%lld %lld", &A[i].first, &A[i].second);

    sort(A.begin(), A.end());

    int ans = 0;
    int min_y = A[0].second;
    for (auto [x, y] : A)
    {
        if (y <= min_y)
        {
            ans++;
            min_y = y;
        }
    }

    printf("%lld\n", ans);
}

signed main()
{
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
}