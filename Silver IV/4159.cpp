/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

bool solve(int N)
{
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] + 200 < A[i + 1])
            return false;
    }
    if (1422 - A[N - 1] > 100)
        return false;
    return true;
}

signed main()
{
    int N;
    while (true)
    {
        scanf("%lld", &N);
        if (N == 0)
            break;
        if (solve(N))
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}