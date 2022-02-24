// 2573 빙산
// https://www.acmicpc.net/source/39530131

#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int map[302][302];
int visited[302][302];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct block
{
    int x;
    int y;
    int time;
};

queue<block> q, melt;

void dfs(int x, int y)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (map[ry][rx] && !visited[ry][rx])
            dfs(rx, ry);
    }
}

int check()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                dfs(j, i);
                cnt++;
            }
        }
    }
    if (cnt > 1)
        return 1;
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            scanf("%d", &map[y][x]);
            if (map[y][x])
                q.push({x, y, 0});
        }

    if (check())
    {
        printf("0");
        return 0;
    }

    int orgin_time = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.time != orgin_time)
        {
            while (!melt.empty())
            {
                auto idx = melt.front();
                melt.pop();
                map[idx.y][idx.x] -= idx.time;
                if (map[idx.y][idx.x] < 0)
                    map[idx.y][idx.x] = 0;
            }

            if (check())
            {
                printf("%d", cur.time);
                return 0;
            }
        }
        orgin_time = cur.time;
        int cnt = 0;
        for (int i = 0; i < 4; i++)
            cnt += !map[cur.y + dy[i]][cur.x + dx[i]];
        if (map[cur.y][cur.x] - cnt > 0)
            q.push({cur.x, cur.y, cur.time + 1});
        melt.push({cur.x, cur.y, cnt});
    }
    printf("0");
    return 0;
}