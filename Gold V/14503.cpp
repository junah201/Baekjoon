/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, +1, 0};

int X, Y;
int sx, sy, sd;
int ans = 0;

vector<vector<int>> inp;

bool check_waste(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inp[ny][nx] == 0)
            return true;
    }
    return false;
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    scanf("%lld %lld %lld", &sy, &sx, &sd);

    inp.resize(Y, vector<int>(X, 1));

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%lld", &inp[y][x]);

    int x = sx, y = sy, d = sd;

    while (true)
    {
        // 1. 현재 칸 청소
        if (inp[y][x] == 0)
        {
            inp[y][x] = 2;
            ans++;
        }
        // 3. 현재 칸의 주변 4칸에 청소되지 않는 빈칸이 있는 경우
        else if (check_waste(x, y))
        {
            for (int i = 0; i < 4; i++)
            {
                // 반시계 방향으로 90도 회전
                d = (d + 3) % 4;
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (inp[ny][nx] == 0)
                {
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        else
        {
            int nx = x - dx[d];
            int ny = y - dy[d];

            // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
            if (inp[ny][nx] == 1)
                break;

            x = nx;
            y = ny;
        }
    }

    printf("%lld", ans);

    return 0;
}