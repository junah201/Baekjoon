// 1600 말이 되고픈 원숭이
// https://www.acmicpc.net/source/39609201

#include <stdio.h>
#include <queue>
using namespace std;

int K, W, H;
int map[202][202];

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int orgin_dx[4] = {1, -1, 0, 0};
int orgin_dy[4] = {0, 0, 1, -1};

int visited[202][202][31];

struct block
{
    int x, y, time, cnt;
};

int bfs()
{
    queue<block> q;
    q.push({0, 0, 0, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.x == W - 1 && cur.y == H - 1)
            return cur.time;

        for (int i = 0; i < 4; i++)
        {
            int rx = cur.x + orgin_dx[i];
            int ry = cur.y + orgin_dy[i];
            if (rx < 0 || ry < 0 || rx >= W || ry >= H)
                continue;
            if (!map[ry][rx] && !visited[ry][rx][cur.cnt])
            {
                visited[ry][rx][cur.cnt] = 1;
                q.push({rx, ry, cur.time + 1, cur.cnt});
            }
        }

        if (cur.cnt < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int rx = cur.x + dx[i];
                int ry = cur.y + dy[i];
                if (rx < 0 || ry < 0 || rx >= W || ry >= H)
                    continue;
                if (!map[ry][rx] && !visited[ry][rx][cur.cnt + 1])
                {
                    visited[ry][rx][cur.cnt + 1] = 1;
                    q.push({rx, ry, cur.time + 1, cur.cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            scanf("%d", &map[y][x]);
    printf("%d", bfs());
    return 0;
}