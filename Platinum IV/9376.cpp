/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, ans = INT_MAX;

signed main()
{
    scanf("%lld", &N);
    vector<pair<int, int>> A;
    vector<int> DP(N, 1);
    for (int i = 0, t1, t2; i < N; i++)
    {
        scanf("%lld %lld", &t1, &t2);
        A.emplace_back(t1, t2);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j].second <= A[i].second)
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans = min(ans, N - DP[i]);
    }

    printf("%lld", ans);

    return 0;
}