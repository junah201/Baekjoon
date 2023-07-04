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

int X, Y, ans = 0;
vector<vector<int>> inp;

int get_sum(int sx, int sy, int ex, int ey)
{
    int result = 0;
    for (int y = sy; y <= ey; y++)
        for (int x = sx; x <= ex; x++)
            result += inp[y][x];

    return result;
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    inp.resize(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &inp[y][x]);

    // 가로 4칸, 세로 4칸
    for (int y = 0; y < Y; y++)
        for (int x = 0; x <= X - 4; x++)
            ans = max(ans, get_sum(x, y, x + 3, y));

    for (int y = 0; y <= Y - 4; y++)
        for (int x = 0; x < X; x++)
            ans = max(ans, get_sum(x, y, x, y + 3));

    // 2 * 2칸
    for (int y = 0; y <= Y - 2; y++)
        for (int x = 0; x <= X - 2; x++)
            ans = max(ans, get_sum(x, y, x + 1, y + 1));

    /*
    ㅁ
    ㅁ
    ㅁㅁ
    */
    for (int y = 0; y <= Y - 3; y++)
        for (int x = 0; x <= X - 2; x++)
        {
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x + 1] - inp[y + 1][x + 1]);
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x] - inp[y + 1][x]);
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y + 1][x + 1] - inp[y + 2][x + 1]);
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y + 1][x] - inp[y + 2][x]);
        }

    for (int y = 0; y <= Y - 2; y++)
        for (int x = 0; x <= X - 3; x++)
        {
            /*
            ㅁ
            ㅁㅁㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y][x + 1] - inp[y][x + 2]);
            /*
                ㅁ
            ㅁㅁㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y][x] - inp[y][x + 1]);
            /*
            ㅁㅁㅁ
            ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y + 1][x + 1] - inp[y + 1][x + 2]);
            /*
            ㅁㅁㅁ
                ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y + 1][x] - inp[y + 1][x + 1]);
        }

    for (int y = 0; y <= Y - 2; y++)
        for (int x = 0; x <= X - 3; x++)
        {
            /*
            ㅁㅁ
              ㅁㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y][x + 2] - inp[y + 1][x]);
            /*
              ㅁㅁ
            ㅁㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y][x] - inp[y + 1][x + 2]);
        }

    for (int y = 0; y <= Y - 3; y++)
        for (int x = 0; x <= X - 2; x++)
        {
            /*
            ㅁ
            ㅁㅁ
              ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x + 1] - inp[y + 2][x]);
            /*
              ㅁ
            ㅁㅁ
            ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x] - inp[y + 2][x + 1]);
        }

    for (int y = 0; y <= Y - 2; y++)
        for (int x = 0; x <= X - 3; x++)
        {
            /*
              ㅁ
            ㅁㅁㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y][x] - inp[y][x + 2]);
            /*
            ㅁㅁㅁ
              ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 2, y + 1) - inp[y + 1][x] - inp[y + 1][x + 2]);
        }

    for (int y = 0; y <= Y - 3; y++)
        for (int x = 0; x <= X - 2; x++)
        {
            /*
            ㅁ
            ㅁㅁ
            ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x + 1] - inp[y + 2][x + 1]);
            /*
              ㅁ
            ㅁㅁ
              ㅁ
            */
            ans = max(ans, get_sum(x, y, x + 1, y + 2) - inp[y][x] - inp[y + 2][x]);
        }

    printf("%lld", ans);

    return 0;
}