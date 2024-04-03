#include <stdio.h>
#include <queue>

using namespace std;

int N, K, T, L;
int map[52][52];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct block
{
    int x;
    int y;
    int cnt;
} s, e, pre[52][52];

deque<block> d;

int bfs()
{

    queue<block> q;
    q.push({s.x, s.y, 1});
    int cost[52][52];
    for (int x = 0; x < 52; x++)
        for (int y = 0; y < 52; y++)
            cost[x][y] = 987654321;
    cost[s.x][s.y] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.x == e.x && cur.y == e.y)
            continue;
        // printf("%d %d %d\n", cur.x, cur.y, cur.cnt);
        for (int i = 0; i < 4; i++)
        {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];

            if (rx <= 0 || ry <= 0 || rx > N || ry > N)
                continue;
            if (cost[rx][ry] > cur.cnt + map[rx][ry])
            {
                pre[rx][ry] = cur;
                // printf("(%d.%d)\n", pre[rx][ry].x, pre[rx][ry].y);
                cost[rx][ry] = cur.cnt + map[rx][ry];
                q.push({rx, ry, cost[rx][ry]});
            }
        }
    }
    return cost[e.x][e.y];
}

int main()
{
    scanf("%d", &N);
    scanf("%d %d %d %d", &s.y, &s.x, &e.y, &e.x);
    scanf("%d", &K);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &L);
        int x1, y1, x2, y2, temp;
        scanf("%d %d", &y1, &x1);
        L--;
        while (L--)
        {
            scanf("%d %d", &y2, &x2);
            if (x1 == x2)
            {
                if (y1 > y2)
                    temp = 1;
                else
                    temp = 0;
                while (y1 != y2)
                {
                    if (temp)
                        map[x1][y1--] += K;
                    else
                        map[x1][y1++] += K;
                }
            }
            else if (y1 == y2)
            {
                if (x1 > x2)
                    temp = 1;
                else
                    temp = 0;
                while (x1 != x2)
                {
                    if (temp)
                        map[x1--][y1] += K;
                    else
                        map[x1++][y1] += K;
                }
            }
            x1 = x2;
            y1 = y2;
        }
        map[x2][y2] += K;
    }
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
            if (map[x][y] == 0)
                map[x][y] = 1;
    printf("%d\n", bfs());

    deque<block> result;

    d.push_back(e);
    auto idx = pre[e.x][e.y];
    d.push_back(idx);
    int cnt = 0;
    while (idx.x != s.x || idx.y != s.y)
    {
        cnt++;
        idx = pre[idx.x][idx.y];
        d.push_back(idx);
    }
    int pos[2];
    auto cur1 = d.back();
    d.pop_back();
    result.push_back(cur1);
    auto cur2 = d.back();
    d.pop_back();
    pos[0] = cur1.x - cur2.x;
    pos[1] = cur1.y - cur2.y;
    cur1 = cur2;
    while (!d.empty())
    {
        cur2 = d.back();
        d.pop_back();
        // printf("(%d, %d) -> (%d, %d)\n", cur1.x, cur1.y, cur2.x, cur2.y);
        // printf("%d %d -> %d %d\n", pos[0], pos[1], cur1.x - cur2.x, cur1.y - cur2.y);
        if (pos[0] != cur1.x - cur2.x || pos[1] != cur1.y - cur2.y)
        {
            result.push_back(cur1);
            pos[0] = cur1.x - cur2.x;
            pos[1] = cur1.y - cur2.y;
        }
        cur1 = cur2;
    }
    if (result.back().x != e.x || result.back().y != e.y)
        result.push_back(e);
    printf("%d ", result.size());
    while (!result.empty())
    {
        auto temp = result.front();
        result.pop_front();
        printf("%d %d ", temp.y, temp.x);
    }
    return 0;
}