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

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int solve()
{
    int L, X, Y;
    scanf("%lld %lld %lld", &L, &Y, &X);
    if (L == 0 && Y == 0 && X == 0)
        return -INT_MAX;

    vector<vector<vector<char>>> inp(L, vector<vector<char>>(Y, vector<char>(X)));
    vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(Y, vector<bool>(X)));
    queue<tuple<int, int, int, int>> q;

    for (int z = 0; z < L; z++)
    {
        for (int y = 0; y < Y; y++)
        {
            for (int x = 0; x < X; x++)
            {
                scanf(" %c", &inp[z][y][x]);

                if (inp[z][y][x] == 'S')
                    q.emplace(x, y, z, 0);
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, z, idx] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
            int rz = z + dz[i];

            if (rx < 0 || rx >= X || ry < 0 || ry >= Y || rz < 0 || rz >= L)
                continue;

            if (inp[rz][ry][rx] == '#')
                continue;

            if (inp[rz][ry][rx] == 'E')
                return idx + 1;

            if (visited[rz][ry][rx])
                continue;

            visited[rz][ry][rx] = true;

            q.emplace(rx, ry, rz, idx + 1);
        }
    }
    return -1;
}

signed main()
{
    while (true)
    {
        int result = solve();
        if (result == -INT_MAX)
            break;
        else if (result == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", result);
    }
    return 0;
}