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

int H, W, L;
int ans = 0;
vector<vector<char>> inp;
vector<char> word;

int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};
vector<vector<vector<int>>> dp;

signed main()
{
    scanf("%lld %lld %lld", &H, &W, &L);
    inp.resize(H, vector<char>(W));
    word.resize(L);
    dp.resize(H, vector<vector<int>>(W, vector<int>(L + 1)));

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            scanf(" %1c", &inp[y][x]);
        }
    }

    for (int i = 0; i < L; i++)
    {
        scanf(" %1c", &word[i]);
    }

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (inp[y][x] == word[0])
                dp[y][x][0] = 1;
        }
    }

    for (int i = 1; i < L; i++)
    {
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                if (inp[y][x] == word[i])
                {
                    for (int j = 0; j < 8; j++)
                    {
                        int rx = x + dx[j];
                        int ry = y + dy[j];

                        if (rx < 0 || rx >= W || ry < 0 || ry >= H)
                            continue;

                        if (inp[ry][rx] != word[i - 1])
                            continue;

                        dp[y][x][i] += dp[ry][rx][i - 1];
                    }
                }
            }
        }
    }

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            ans += dp[y][x][L - 1];
        }
    }

    printf("%lld", ans);

    return 0;
}
