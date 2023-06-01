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

int N, ans;
vector<vector<int>> init_inp;
// U D R L
vector<vector<int>> move(int dir, vector<vector<int>> inp)
{
    vector<vector<int>> checker(N, vector<int>(N, false));
    // U
    if (dir == 0)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                int init_value = inp[y][x];
                for (int ny = y - 1; ny >= 0; ny--)
                {
                    if (checker[ny][x])
                        break;
                    if (inp[ny][x] == 0)
                    {
                        inp[ny][x] = inp[ny + 1][x];
                        inp[ny + 1][x] = 0;
                    }
                    else if (inp[ny][x] == init_value)
                    {
                        inp[ny][x] *= 2;
                        inp[ny + 1][x] = 0;
                        checker[ny][x] = true;
                        break;
                    }
                    else if (inp[ny][x] != init_value)
                    {
                        break;
                    }
                }
            }
        }
    }
    // D
    else if (dir == 1)
    {
        for (int y = N - 1; y >= 0; y--)
        {
            for (int x = 0; x < N; x++)
            {
                int init_value = inp[y][x];
                for (int ny = y + 1; ny < N; ny++)
                {
                    if (checker[ny][x])
                        break;
                    if (inp[ny][x] == 0)
                    {
                        inp[ny][x] = inp[ny - 1][x];
                        inp[ny - 1][x] = 0;
                    }
                    else if (inp[ny][x] == init_value)
                    {
                        inp[ny][x] *= 2;
                        inp[ny - 1][x] = 0;
                        checker[ny][x] = true;
                        break;
                    }
                    else if (inp[ny][x] != init_value)
                    {
                        break;
                    }
                }
            }
        }
    }
    // R
    else if (dir == 2)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                int init_value = inp[y][x];

                for (int nx = x - 1; nx >= 0; nx--)
                {
                    if (checker[y][nx])
                        break;
                    if (inp[y][nx] == 0)
                    {
                        inp[y][nx] = inp[y][nx + 1];
                        inp[y][nx + 1] = 0;
                    }
                    else if (inp[y][nx] == init_value)
                    {
                        inp[y][nx] *= 2;
                        inp[y][nx + 1] = 0;
                        checker[y][nx] = true;
                        break;
                    }
                    else if (inp[y][nx] != init_value)
                    {
                        break;
                    }
                }
            }
        }
    }
    // L
    else if (dir == 3)
    {
        for (int x = N - 1; x >= 0; x--)
        {
            for (int y = 0; y < N; y++)
            {
                int init_value = inp[y][x];
                for (int nx = x + 1; nx < N; nx++)
                {
                    if (checker[y][nx])
                        break;
                    if (inp[y][nx] == 0)
                    {
                        inp[y][nx] = inp[y][nx - 1];
                        inp[y][nx - 1] = 0;
                    }
                    else if (inp[y][nx] == init_value)
                    {
                        inp[y][nx] *= 2;
                        inp[y][nx - 1] = 0;
                        checker[y][nx] = true;
                        break;
                    }
                    else if (inp[y][nx] != init_value)
                    {
                        break;
                    }
                }
            }
        }
    }

    return inp;
}

void dfs(int cnt, vector<vector<int>> inp)
{
    if (cnt >= 5)
    {
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                ans = max(ans, inp[y][x]);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> moved_inp = move(i, inp);
        dfs(cnt + 1, moved_inp);
    }
}

signed main()
{
    scanf("%lld", &N);
    init_inp.resize(N, vector<int>(N));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &init_inp[y][x]);
        }
    }

    dfs(0, init_inp);

    printf("%lld", ans);

    return 0;
}