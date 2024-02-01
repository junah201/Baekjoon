/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int X, Y, sx, sy;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<char>> inp;
vector<vector<int>> visited;

void bfs(int tx, int ty)
{
    char start = inp[ty][tx];
    queue<pair<int, int>> q;
    q.emplace(tx, ty);
    visited[ty][tx] = 3;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                continue;
            if (visited[ny][nx])
                continue;
            if (inp[ny][nx] != inp[y][x])
                continue;

            visited[ny][nx] = 2;
            q.emplace(nx, ny);
        }
    }
}

signed main()
{
    scanf("%lld %lld", &Y, &X);
    visited.resize(Y, vector<int>(X, 0));
    inp.resize(Y, vector<char>(X));

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %1c", &inp[y][x]);
        }
    }

    scanf("%lld %lld", &sy, &sx);
    sx -= 1;
    sy -= 1;

    char oper[200002];
    scanf(" %s", oper);

    int len = strlen(oper);
    for (int i = 0; i < len; i++)
    {
        // 와드
        if (oper[i] == 'W')
        {
            bfs(sx, sy);
        }
        // 위
        else if (oper[i] == 'U')
        {
            sy -= 1;
        }
        // 아래
        else if (oper[i] == 'D')
        {
            sy += 1;
        }
        // 왼쪽
        else if (oper[i] == 'L')
        {
            sx -= 1;
        }
        // 오른쪽
        else if (oper[i] == 'R')
        {
            sx += 1;
        }
    }

    visited[sy][sx] = 4;
    for (int i = 0; i < 4; i++)
    {
        int nx = sx + dx[i];
        int ny = sy + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

        visited[ny][nx] = 4;
    }
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (visited[y][x])
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}