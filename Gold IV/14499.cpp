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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dice[6] = {1, 2, 3, 4, 5, 6};
vector<vector<int>> dice_map
{
    {
        3, 2, 1, 4},
        {3, 2, 5, 0},
    {
    }
}

signed main()
{
    int X, Y, sx, se, K;
    scanf("%lld %lld %lld %lld %lld", &Y, &X, &sx, &se, &K);
    vector<vector<int>> inp(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &inp[y][x]);

    return 0;
}