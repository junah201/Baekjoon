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

int bfs(char default_key[30])
{
    bool visited[33554431][102][102];
    int result = 0;
    queue<info> q;

    int len = strlen(default_key);
    int orgin_key = 0;
    if (default_key[0] != '0')
        for (int i = 0; i < len; i++)
            orgin_key = orgin_key | (default_key[i] - 'a');

    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            if ((x == 0 || y == 0 || x == W - 1 || y == H - 1) && inp[y][x] == '*')
                q.push({x, y, orgin_key});

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
            // 이미 갔던 칸
            if (visited[cur.key][ry][rx])
                continue;
            // 벽
            if (inp[ry][rx] == '*')
                continue;
            // 문서
            if (inp[ry][rx] == '$')
            {
                visited[cur.key][ry][rx] = 1;
                inp[ry][rx] = '.';
                result++;
                q.push({rx, ry, cur.key});
            }
            // 열쇠
            if (inp[ry][rx] >= 'a' && inp[ry][rx] <= 'z')
            {
                visited[cur.key | (keys[inp[ry][rx] - 'a'])][ry][rx] = 1;
                q.push({rx, ry, cur.key | (keys[inp[ry][rx] - 'a'])});
            }
        }
    }
    return result;
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
        char default_key[30];
        scanf("%s", default_key);
        printf("%d\n", bfs(default_key));
    }
    return 0;
}