/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N;

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    int now = A[0];
    int cnt = 0;
    int ans = 0;

    for (int i = 1; i < N; i++)
    {
        if (now > A[i])
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 0;
            now = A[i];
        }
    }

    printf("%lld", ans);

    return 0;
}