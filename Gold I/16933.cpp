/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M, K;
int inp[1002][1002];
int check[1002][1002][12];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<tuple<int, int, int, int, int>> q;

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%1d", &inp[y][x]);

    q.emplace(0, 0, 1, 0, 1);

    // day    1 : 낮, 0 : 밤
    while (!q.empty())
    {
        auto [x, y, dis, 대충부순칸개수, day] = q.front();
        q.pop();

        dprintf("(%d %d) dis : %d ", x, y, dis);
        dprintf("is : %d day : %d\n", 대충부순칸개수, day);

        if (x == M - 1 && y == N - 1)
        {
            printf("%d", dis);
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int rx = dx[i] + x;
            int ry = dy[i] + y;

            if (rx < 0 || rx >= M || ry < 0 || ry >= N)
                continue;

            if (check[ry][rx][대충부순칸개수])
                continue;

            // 다음칸이 빈칸 일때
            if (inp[ry][rx] == 0)
            {
                check[ry][rx][대충부순칸개수] = dis + 1;
                q.emplace(rx, ry, dis + 1, 대충부순칸개수, !day);
            }
            // 다음 칸이 벽이고, 낮일 때
            if (inp[ry][rx] == 1 && day == 1 && 대충부순칸개수 < K)
            {
                check[ry][rx][대충부순칸개수] = dis + 1;
                q.emplace(rx, ry, dis + 1, 대충부순칸개수 + 1, !day);
            }
            // 다음 칸이 벽이고, 밤이여서 한턴 쉴 때
            if (inp[ry][rx] == 1 && day == 0 && 대충부순칸개수 < K)
            {
                q.emplace(x, y, dis + 1, 대충부순칸개수, !day);
            }
        }
    }
    printf("-1");
    return 0;
}
