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

int X, Y, ans;
vector<vector<char>> inp;
queue<tuple<int, int, int, int>> q;

int alpha[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int checker, int cnt)
{
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

        if (checker & alpha[inp[ny][nx] - 'A'])
            continue;

        dfs(nx, ny, checker | alpha[inp[ny][nx] - 'A'], cnt + 1);
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);

    inp.resize(Y, vector<char>(X));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &inp[y][x]);
        }
    }

    for (int i = 0; i <= 'Z' - 'A'; i++)
    {
        alpha[i] = 1 << i;
    }

    dfs(0, 0, alpha[inp[0][0] - 'A'], 1);

    printf("%lld", ans);

    return 0;
}