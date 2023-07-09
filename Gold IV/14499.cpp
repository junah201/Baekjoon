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

int dice[7] = {0, 0, 0, 0, 0, 0, 0};
vector<vector<int>> dice_map{
    {},
    {3, 4, 5, 2, 6},
    {3, 4, 1, 6, 5},
    {6, 1, 5, 2, 4},
    {1, 6, 5, 2, 3},
    {3, 4, 6, 1, 2},
    {3, 4, 2, 5, 1}};

int X, Y, sx, sy, K;

void print_inp(vector<vector<int>> &inp, int nx, int ny)
{
    for (int y = 0; y < Y; y++)
    {

        for (int x = 0; x < X; x++)
        {
            if (nx == x && ny == y)
                printf(".");
            printf("%lld ", inp[y][x]);
        }
        printf("\n");
    }
    for (int i = 1; i <= 7; i++)
    {
        printf("%lld ", dice[i]);
    }
    printf("\n");
}

signed main()
{
    scanf("%lld %lld %lld %lld %lld", &Y, &X, &sx, &sy, &K);
    vector<vector<int>> inp(Y, vector<int>(X));
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &inp[y][x]);

    print_inp(inp, 0, 0);

    int x = sx, y = sy, now_dice = 6;
    while (K--)
    {
        int oper;
        scanf("%lld", &oper);

        int nx = x + dx[oper - 1];
        int ny = y + dy[oper - 1];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

        int new_dice = dice_map[now_dice][oper - 1];

        if (inp[ny][nx] == 0)
        {
            inp[ny][nx] = dice[new_dice];
        }
        else
        {
            dice[new_dice] = inp[ny][nx];
            inp[ny][nx] = 0;
        }

        printf("new_dice: %lld\n", new_dice);
        print_inp(inp, nx, ny);

        x = nx;
        y = ny;
        now_dice = new_dice;
        printf("%lld\n", dice[dice_map[now_dice][4]]);
    }

    return 0;
}