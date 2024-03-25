/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int Y, X;
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
vector<vector<int>> inp;

int ans = 0;

void get(int x, int y, int sum)
{
    if (x == X - 1 && y == Y - 1)
    {
        ans = max(ans, sum + inp[y][x]);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            continue;

        get(rx, ry, sum + inp[y][x]);
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf("%lld", &inp[y][x]);
        }
    }

    get(0, 0, 0);
    printf("%lld", ans);

    return 0;
}
