/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int N;
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());

    for (auto i : A)
    {
        printf("%lld ", i);
    }

    return 0;
}