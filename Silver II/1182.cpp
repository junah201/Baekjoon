/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, ans;
vector<int> A;

void dfs(int idx, int sum, int cnt)
{
    if (idx == N)
    {
        if (sum == M && cnt)
            ans++;
        return;
    }

    dfs(idx + 1, sum + A[idx], cnt + 1);
    dfs(idx + 1, sum, cnt);
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    A.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    dfs(0, 0, 0);

    printf("%lld", ans);

    return 0;
}