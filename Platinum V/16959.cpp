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
vector<vector<int>> dx(3);
vector<vector<int>> dy(3);

int knight_dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int knight_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bishop_dx[4] = {1, 1, -1, -1};
int bishop_dy[4] = {1, -1, 1, -1};

int look_dx[4] = {1, -1, 0, 0};
int look_dy[4] = {0, 0, 1, -1};

queue<tuple<int, int, int, int, int>> q;
int inp[12][12];
int max_idx = 1;
int visited[102][12][12][3];

void print_visited(int idx, int type)
{
    dprintf("idx: %lld, type: %lld\n", idx, type);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (visited[idx][y][x][type] == INT_MAX)
                dprintf("-1 ");
            else
                dprintf("%lld ", visited[idx][y][x][type]);
        }
        dprintf("\n");
    }
}

signed main()
{
    scanf("%lld", &N);

    // for (int i = 0; i < 102; i++)
    // {
    //     for (int y = 0; y < N; y++)
    //     {
    //         for (int x = 0; x < N; x++)
    //         {
    //             for (int k = 0; k < 3; k++)
    //             {
    //                 visited[i][y][x][k] = INT_MAX;
    //             }
    //         }
    //     }
    // }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &inp[y][x]);
            if (inp[y][x] == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    q.emplace(x, y, i, 0, 1);
                    visited[1][y][x][i] = 0;
                }
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, type, time, idx] = q.front();
        q.pop();

        // if (idx < max_idx)
        //     continue;

        dprintf("\n");
        dprintf("max_idx: %lld, idx: %lld\n", max_idx, idx);
        dprintf("(%lld %lld), type:%lld, time%lld\n", x, y, type, time, idx);

        // 말 교체
        for (int i = 0; i < 3; i++)
        {
            if (type == i)
                continue;

            if (visited[idx][y][x][i])
                continue;

            dprintf("change (%lld %lld) %lld\n", x, y, i);

            visited[idx][y][x][i] = true;
            q.emplace(x, y, i, time + 1, idx);
        }

        vector<pair<int, int>> new_xy(0);

        // 나이트
        if (type == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + knight_dx[i];
                int ny = y + knight_dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;

                if (visited[idx][ny][nx][type])
                    continue;

                new_xy.emplace_back(nx, ny);
            }
        }
        // 비숍 - 대각선
        else if (type == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0;; j++)
                {
                    int nx = x + bishop_dx[i] * j;
                    int ny = y + bishop_dy[i] * j;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        break;

                    if (visited[idx][ny][nx][type])
                        continue;

                    new_xy.emplace_back(nx, ny);
                }
            }
        }
        // 룩 - 상하좌우
        else if (type == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0;; j++)
                {
                    int nx = x + look_dx[i] * j;
                    int ny = y + look_dy[i] * j;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        break;

                    if (visited[idx][ny][nx][type])
                        continue;

                    new_xy.emplace_back(nx, ny);
                }
            }
        }

        dprintf("new_xy size : %lld\n", new_xy.size());

        for (auto [nx, ny] : new_xy)
        {
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            visited[idx][ny][nx][type] = true;

            dprintf("next (%lld %lld)\n", nx, ny);

            if (idx + 1 == inp[ny][nx])
            {
                if (inp[ny][nx] == N * N)
                {
                    printf("%lld", time + 1);
                    return 0;
                }

                visited[idx + 1][ny][nx][type] = true;
                max_idx = max(max_idx, inp[ny][nx]);
                q.emplace(nx, ny, type, time + 1, idx + 1);
            }
            else
                q.emplace(nx, ny, type, time + 1, idx);
        }
    }

    print_visited(2, 0);
    print_visited(2, 1);
    print_visited(2, 2);

    dprintf("end %lld", max_idx);

    return 0;
}