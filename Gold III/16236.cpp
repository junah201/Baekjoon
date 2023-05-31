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

int N, ans, pery_cnt;
vector<vector<int>> inp;
pair<int, int> start;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

tuple<int, int, int> get_next_pery(int start_x, int start_y, int start_size)
{
    int result_time = -1;
    priority_queue<pair<int, int>> results;

    queue<tuple<int, int, int, int>> q;
    vector<vector<char>> visited(N, vector<char>(N, false));
    q.emplace(start_x, start_y, start_size, 1);
    visited[start_y][start_x] = true;

    while (!q.empty())
    {
        auto [x, y, size, time] = q.front();
        q.pop();

        if (result_time != -1 && result_time < time)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (visited[ny][nx])
                continue;

            if (inp[ny][nx] > size)
                continue;

            if (inp[ny][nx] < size && inp[ny][nx] != 0 && (result_time == -1 || result_time == time))
            {
                result_time = time;
                results.emplace(-ny, -nx);
            }

            visited[ny][nx] = true;
            q.emplace(nx, ny, size, time + 1);
        }
    }

    if (result_time == -1)
        return {-1, -1, -1};

    return {-results.top().second, -results.top().first, result_time};
}

signed main()
{
    scanf("%lld", &N);
    inp.resize(N, vector<int>(N));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%lld", &inp[y][x]);
            if (inp[y][x] == 9)
            {
                start = {x, y};
                inp[y][x] = 0;
            }
        }
    }

    int x = start.first, y = start.second, size = 2;

    while (true)
    {
        auto [nx, ny, time] = get_next_pery(x, y, size);

        if (nx == -1 && ny == -1 && time == -1)
            break;

        dprintf("ans:%lld time:%lld\n", ans, time);
        dprintf("(%lld %lld) size:%lld -> %lld\n", nx, ny, size, inp[ny][nx]);

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (x == nx && y == ny)
                    dprintf("■ ");
                else
                    dprintf("%lld ", inp[y][x]);
            }
            dprintf("\n");
        }

        inp[ny][nx] = 0;

        x = nx;
        y = ny;
        pery_cnt++;

        if (size == pery_cnt)
        {
            size++;
            pery_cnt = 0;
        }

        ans += time;
    }

    printf("%lld", ans);

    return 0;
}