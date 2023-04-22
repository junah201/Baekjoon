/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

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
vector<vector<int>> inp;
int ans[3];

void get(int sx, int sy, int gap)
{
    int idx = inp[sy][sx];

    for (int y = sy; y < sy + gap; y++)
    {
        for (int x = sx; x < sx + gap; x++)
        {
            if (inp[y][x] != idx)
            {
                int new_gap = gap / 3;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        get(sx + new_gap * i, sy + new_gap * j, new_gap);
                    }
                }
                return;
            }
        }
    }
    ans[idx + 1]++;
}

signed main()
{
    scanf("%lld", &N);
    inp.resize(N, vector<int>(N));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%lld", &inp[y][x]);

    get(0, 0, N);

    for (int i = 0; i < 3; i++)
    {
        printf("%lld\n", ans[i]);
    }

    return 0;
}