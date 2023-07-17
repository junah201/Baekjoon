#include <stdio.h>
#include <queue>

using namespace std;

int X, Y;
int map[72][102];
int visited[72][102];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int cnt;

bool bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    visited[sy][sx] = 1;

    bool result = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
                continue;

            if (map[y][x] < map[ny][nx])
                result = false;

            if (visited[ny][nx])
                continue;

            if (map[y][x] != map[ny][nx])
                continue;

            visited[ny][nx] = 1;
            q.emplace(nx, ny);
        }
    }

    return result;
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
        {
            scanf("%d", &map[y][x]);
        }

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
        {
            if (visited[y][x])
                continue;

            if (bfs(x, y))
                cnt++;
        }

    printf("%d", cnt);
    return 0;
}