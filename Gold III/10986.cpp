/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, ans;

signed main()
{
    scanf("%lld %lld", &N, &M);
    vector<int> A(N + 1);
    vector<int> cnt(M + 1);
    int sum = 0;
    cnt[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
        sum += A[i];
        cnt[sum % M]++;
    }

    for (int i = 0; i < M; i++)
    {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    printf("%lld", ans);

    return 0;
}