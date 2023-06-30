/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;
vector<pair<int, int>> A;
vector<char> visited(1000000, false);
vector<int> ans;
bool is_end = false;
bool is_possible = true;

void dfs(int idx)
{
    if (idx == N)
    {
        is_end = true;
        return;
    }
    if (!visited[A[idx].first])
    {
        visited[A[idx].first] = true;
        ans[idx] = A[idx].first;
        dfs(idx + 1);
        visited[A[idx].first] = false;
    }
    else if (!visited[A[idx].second])
    {
        visited[A[idx].second] = true;
        ans[idx] = A[idx].second;
        dfs(idx + 1);
        visited[A[idx].second] = false;
    }
}

signed main()
{
    scanf("%lld", &N);
    A.resize(N);
    ans.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &A[i].first, &A[i].second);
    }

    dfs(0);

    if (!is_end)
    {
        printf("-1");
        return 0;
    }

    for (int i = 0; i < N; i++)
        printf("%lld\n", ans[i]);

    return 0;
}