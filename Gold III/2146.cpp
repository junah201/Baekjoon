#include <bits/stdc++.h>
using namespace std;

int N, ans = INT_MAX, cnt = 2;
int inp[101][101];

vector<vector<pair<int, int>>> land;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int value)
{
    inp[y][x] = value;
    land[value].push_back({x, y});

    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= N || ry < 0 || ry >= N)
            continue;

        if (inp[ry][rx] == 1)
            dfs(rx, ry, value);
    }
}

int bfs(int idx)
{
    struct block
    {
        int x, y, dis;
    };

    bool visited[101][101] = {
        false,
    };

    queue<block> q;
    for (auto i : land[idx])
        q.push({i.first, i.second, 0});

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, dis = q.front().dis;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= N || ry < 0 || ry >= N)
                continue;

            if (inp[ry][rx] == 0 && !visited[ry][rx])
            {
                visited[ry][rx] = true;
                q.push({rx, ry, dis + 1});
            }

            else if (inp[ry][rx] != idx && inp[ry][rx] != 0)
                return dis;
        }
    }

    return INT_MAX;
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &inp[y][x]);

    land.push_back({});
    land.push_back({});

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (inp[y][x] == 1)
            {
                land.push_back({});
                dfs(x, y, cnt);
                cnt++;
            }

    for (int i = 1; i < land.size(); i++)
        ans = min(ans, bfs(i));

    printf("%d", ans);
    return 0;
}