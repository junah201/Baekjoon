/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
vector<vector<double>> DP;
vector<pair<int, int>> inp;

double dist(int from, int to)
{
    auto [sx, sy] = inp[from];
    auto [ex, ey] = inp[to];

    return sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey));
}

double get(int idx, int sidx, int hidx)
{
    if (idx == N - 1)
    {
        return dist(sidx, idx) + dist(hidx, idx);
    }

    if (DP[sidx][hidx] != -1)
        return DP[sidx][hidx];

    DP[sidx][hidx] = INF;
    DP[sidx][hidx] = min(DP[sidx][hidx], get(idx + 1, idx, hidx) + dist(sidx, idx));
    DP[sidx][hidx] = min(DP[sidx][hidx], get(idx + 1, sidx, idx) + dist(hidx, idx));

    return DP[sidx][hidx];
}

void solve()
{
    scanf("%lld", &N);
    inp.resize(0);
    inp.resize(N + 2);
    DP.resize(0);
    DP.resize(N + 2, vector<double>(N + 2, -1));
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }
    printf("%.12lf\n", get(1, 0, 0));
}

signed main()
{
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}