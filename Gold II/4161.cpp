// 4161  나이트의 여행
//

#include <stdio.h>
#include <queue>

using namespace std;

int T, N;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct block
{
    int x;
    int y;
    int time;
} idx, input, result;

int bfs()
{
    int map[302][302] = {
        0,
    };
    int check[302][302] = {
        0,
    };
    queue<block> q;
    q.push({input.x, input.y, 0});
    while (!q.empty())
    {
        idx = q.front();
        q.pop();
        if (idx.x == result.x && idx.y == result.y)
            return idx.time;
        for (int i = 0; i < 8; i++)
        {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];

            if (rx < N && ry < N && rx >= 0 && ry >= 0 && check[ry][rx] == 0)
            {
                check[ry][rx] = 1;
                q.push({rx, ry, idx.time + 1});
            }
        }
    }
    return -1;
}

int main()
{
    while (1)
    {
        scanf("%d %d", &input.x, &input.y);
        if (input.x == 'E')
            return 0;
        printf("%d\n", bfs());
    }
    return 0;
}