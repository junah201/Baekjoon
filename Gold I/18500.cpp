/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int X, Y, N;
char inp[102][102], tmp;
int visited[102][102];
vector<pair<int, int>> block;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void reset_visited()
{
    for (int y = Y - 1; y > 0; y--)
    {
        for (int x = 0; x < X; x++)
            visited[y][x] = 0;
    }
}

void bfs(int idx, int sx, int sy)
{
    block.clear();
    queue<tuple<int, int>> q;
    q.emplace(sx, sy);
    visited[sy][sx] = idx;
    block.emplace_back(sx, sy);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx > X || ry < 0 || ry > Y)
                continue;

            if (inp[ry][rx] != 'x')
                continue;

            if (visited[ry][rx] == idx)
                continue;

            visited[ry][rx] = idx;
            block.emplace_back(rx, ry);
            q.emplace(rx, ry);
        }
    }
}

int throw_stick(int side, int y)
{
    // 왼쪽
    if (side == 1)
    {
        for (int x = 0; x < X; x += 1)
        {
            if (inp[y][x] == 'x')
            {
                inp[y][x] = '.';
                return 1;
            }
        }
    }
    // 오른쪽
    else
    {
        for (int x = X - 1; x >= 0; x -= 1)
        {
            if (inp[y][x] == 'x')
            {
                inp[y][x] = '.';
                return 1;
            }
        }
    }

    return 0;
}

int fall(int idx)
{
    while (true)
    {
        // 한칸 내릴 수 있는지 확인하기
        for (auto [x, y] : block)
        {
            if (inp[y - 1][x] == '.')
                continue;
            if (inp[y - 1][x] == 'x' && visited[y - 1][x] == idx)
                continue;
            return 0;
        }
        // 한칸 내리기
        queue<pair<int, int>> tmp;
        for (auto [x, y] : block)
        {
            if (inp[y - 1][x] == 'x')
            {
                tmp.emplace(x, y);
                continue;
            }
            inp[y - 1][x] = 'x';
            inp[y][x] = '.';
        }
        while (!tmp.empty())
        {
            auto [x, y] = tmp.front();
            tmp.pop();

            if (inp[y - 1][x] == 'x')
            {
                tmp.emplace(x, y);
                continue;
            }

            inp[y - 1][x] = 'x';
            inp[y][x] = '.';
        }
        // 새 백터 만들기
        vector<pair<int, int>> new_block;
        for (auto [x, y] : block)
        {
            new_block.emplace_back(x, y - 1);
            visited[y - 1][x] = visited[y][x];
        }
        block = new_block;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int x = 0; x < X; x++)
        inp[0][x] = 'x';
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
        {
            scanf(" %c", &tmp);
            inp[Y - y][x] = tmp;
        }

    scanf("%d", &N);
    for (int i = 1, R; i <= N; i++)
    {
        reset_visited();
        scanf("%d", &R);
        if (throw_stick(i % 2, R))
        {
            bfs(i, 0, 0);
            int idx = -1;
            for (int y = 0; y < Y; y++)
                for (int x = 0; x < X; x++)
                {
                    if (visited[y][x] != i && inp[y][x] == 'x' && visited[y][x] >= 0)
                    {
                        bfs(idx, x, y);
                        fall(idx);
                        idx--;
                    }
                }
        }
    }

    for (int y = Y; y > 0; y--)
    {
        for (int x = 0; x < X; x++)
            printf("%c", inp[y][x]);
        printf("\n");
    }

    return 0;
}