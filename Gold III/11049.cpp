/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
vector<pair<int, int>> inp;
vector<vector<int>> dp;

int get_value2(int start1, int start2, int end1, int end2)
{
    return inp[start1].first * inp[start2].second * inp[end2].second;
}

int get_value(int start, int end)
{
    if (dp[start][end] != 0)
        return dp[start][end];

    if (start == end)
        return 0;

    if (start + 1 == end)
    {
        return dp[start][end] = get_value2(start, start, end, end);
    }

    int res = INF;
    for (int i = start; i < end; i++)
    {
        res = min(res, get_value(start, i) + get_value(i + 1, end) + get_value2(start, i, i + 1, end));
    }
    dp[start][end] = res;
    return dp[start][end];
}

signed main()
{
    scanf("%lld", &N);
    inp.resize(N);
    dp.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }

    int ans = INF;
    // for (int i = 1; i < N; i++)
    // {
    //     ans = min(ans, get_value(0, i) + get_value(i + 1, N - 1));
    // }
    printf("%lld", get_value(0, N - 1));

    return 0;
}