/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N, tmp, ans = -INF;

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, A[i] * (N - i));
    }

    printf("%lld", ans);

    return 0;
}