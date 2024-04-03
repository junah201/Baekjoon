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

int N, W;
pair<int, int> inp[1002];
vector<vector<tuple<int, int, int, int>>> DP(2002, vector<tuple<int, int, int, int>>(2002, {-1, -1, -1, -1}));

int solve(int idx, int sidx, int hidx)
{
    // printf("idx:%lld s:%lld h:%lld\n", idx, sidx, hidx);
    if (idx == W + 1)
        return 0;

    auto [dp_value, dp_car, pre_sidx, pre_hidx] = DP[sidx][hidx];

    if (dp_value != -1)
        return dp_value;

    int res = INF;
    auto [sx, sy] = inp[sidx];
    auto [hx, hy] = inp[hidx];
    auto [ix, iy] = inp[idx];

    res = min(res, solve(idx + 1, idx, hidx) + abs(sx - ix) + abs(sy - iy));
    DP[sidx][hidx] = {res, 1, idx, hidx};

    int res2 = solve(idx + 1, sidx, idx) + abs(hx - ix) + abs(hy - iy);
    if (res > res2)
    {
        DP[sidx][hidx] = {res2, 2, sidx, idx};
    }

    return min(res, res2);
}

signed main()
{
    scanf("%lld", &N);
    scanf("%lld", &W);
    inp[0] = {1, 1};
    inp[2001] = {N, N};
    for (int i = 1; i <= W; i++)
    {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }
    printf("%lld\n", solve(1, 0, 2001));

    int sidx = 0, hidx = 2001;
    while (true)
    {
        auto [dp_value, dp_car, pre_sidx, pre_hidx] = DP[sidx][hidx];
        printf("%lld\n", dp_car);
        sidx = pre_sidx;
        hidx = pre_hidx;

        if (max(sidx, hidx) == W)
            break;
    }

    return 0;
}