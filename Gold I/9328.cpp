#include <bits/stdc++.h>
using namespace std;

int T, H, W;
char inp[102][102];

int keys[26];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct info
{
    int x;
    int y;
    int key;
};

void set_keys()
{
    for (int i = 0, temp = 1; i < 26; i++)
    {
        keys[i] = temp;
        temp *= 2;
    }
}

int bfs()
{
    int result = 0;
    queue<info> q;
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            if ((x == 0 || y == 0 || x == W - 1 || y == H - 1) && inp[y][x] == '*')
                q.push({x, y, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];

            // 범위 밖
            if (rx < 0 || ry < 0 || rx >= W || ry >= H)
                continue;
            // 벽
            if (inp[ry][rx] == '*')
                continue;
            // 문서
            if (inp[ry][rx] == '$')
            {
                inp[ry][rx] = '.';
            }
        }
    }
}
int main()
{
    set_keys();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &H, &W);
        for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
                scanf(" %c", &inp[y][x]);
    }
    return 0;
}