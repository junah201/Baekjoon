/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, M;
int inp[1002][1002];
int ans[1002][1002];
bool visited[1002][1002];
vector<int> id;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy)
{
    int result = 1;
    queue<tuple<int, int>> q;
    vector<tuple<int, int>> wall;
    q.emplace(sx, sy);
    visited[sy][sx] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= M || ry < 0 || ry >= N)
                continue;

            if (visited[ry][rx])
                continue;

            visited[ry][rx] = true;

            if (inp[ry][rx] == 1)
            {
                wall.emplace_back(rx, ry);
                continue;
            }
            else if (inp[ry][rx] == 0)
            {
                result++;
                q.emplace(rx, ry);
            }
        }
    }
    for (auto [x, y] : wall)
    {
        ans[y][x] += result;
        visited[y][x] = false;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    id.push_back(0);

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%1d", &inp[y][x]);

    for (int y = 0, idx = 1; y < N; y++)
        for (int x = 0; x < M; x++)
            if (inp[y][x] == 0 && visited[y][x] == false)
            {
                bfs(x, y);
            }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
            printf("%d", (ans[y][x] + inp[y][x]) % 10);
        printf("\n");
    }

    return 0;
}