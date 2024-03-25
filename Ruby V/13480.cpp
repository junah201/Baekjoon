/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX
#define MAX_H 60
#define MAX_W 60

int N;
vector<vector<pair<int, vector<tuple<int, int, int, int, int>>>>> DP(MAX_H + 1, vector<pair<int, vector<tuple<int, int, int>>>>(MAX_W + 1));

void solve()
{
    int W, H;
    scanf("%lld %lld", &W, &H);
}

signed main()
{
    for (int h = 1; h <= MAX_H; h++)
    {
        for (int w = 1; w <= MAX_W; w++)
        {
            // * : DP 초기화
            if (w == h)
            {
                DP[h][w] = {1, {{0, 0, h - 1, w - 1, h}}};
            }
            else
            {
                DP[h][w] = {h * w, {{0, 0, h - 1, w - 1, 1}}};
            }
        }
    }

    // * : DP 계산
    for (int h = 1; h <= MAX_H; h++)
    {
        for (int w = 1; w <= MAX_W; w++)
        {
            int tmp_ans = INF;
            bool is_dh = true;
            int val = 1;
            // * : 작은 DP로 큰 DP 만들기
            // * : 세로로 분할
            for (int dh = h + 1; dh <= MAX_H - 1; dh++)
            {
            }
            // * : 가로로 분할
        }
    }

    scanf("%lld", &N);
    while (N--)
    {
        solve();
    }
    return 0;
}