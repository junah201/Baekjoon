// 1194 달이 차오른다, 가자.
// https://www.acmicpc.net/source/39756674

#include <bits/stdc++.h>
using namespace std;

int N, M;
char inp[52][52];
int visited[64][52][52];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int keys[6] = {1, 2, 4, 8, 16, 32};

struct info
{
    int x;
    int y;
    int time;
    int key;
};

queue<info> q;

int bfs()
{
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (inp[y][x] == '0')
                q.push({x, y, 0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];

            // 범위 밖으로
            if (rx < 0 || ry < 0 || rx >= M || ry >= N)
                continue;
            // 벽
            if (inp[ry][rx] == '#')
                continue;
            // 이미 갔던 칸
            if (visited[cur.key][ry][rx])
                continue;
            // 열쇠
            if (inp[ry][rx] >= 'a' && inp[ry][rx] <= 'f')
            {
                visited[cur.key | keys[inp[ry][rx] - 'a']][ry][rx] = 1;
                q.push({rx, ry, cur.time + 1, cur.key | keys[inp[ry][rx] - 'a']});
            }
            // 문
            if (inp[ry][rx] >= 'A' && inp[ry][rx] <= 'F')
                if (cur.key & keys[inp[ry][rx] - 'A'])
                {
                    visited[cur.key][ry][rx] = 1;
                    q.push({rx, ry, cur.time + 1, cur.key});
                }
            // 빈 칸

            if (inp[ry][rx] == '.' || inp[ry][rx] == '0')
            {
                visited[cur.key][ry][rx] = 1;
                q.push({rx, ry, cur.time + 1, cur.key});
            }
            // 출구
            if (inp[ry][rx] == '1')
                return cur.time + 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", inp[i]);
    printf("%d", bfs());
    return 0;
}