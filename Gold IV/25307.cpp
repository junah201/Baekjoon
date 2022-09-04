#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int inp[2002][2002];
int check[2002][2002];

pair<int, int> start;
vector<pair<int, int>> 마네킹;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void 마네킹_탐색(int x, int y, int stk)
{
    if (stk > K)
        return;

    if (check[y][x])
        return;

    check[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= M || ry < 0 || ry >= N)
            continue;

        마네킹_탐색(rx, ry, stk + 1);
    }
}

struct xy
{
    int x;
    int y;
    int stk;
};

int bfs()
{
    queue<xy> q;
    q.push({start.first, start.second, 0});

    while (!q.empty())
    {
        auto [x, y, stk] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || rx >= M || ry < 0 || ry >= N)
                continue;

            if (inp[ry][rx] == 1 || inp[ry][rx] == 3 || inp[ry][rx] == 4)
                continue;

            if (check[ry][rx])
                continue;

            if (inp[ry][rx] == 2)
                return stk + 1;

            check[ry][rx] = 1;
            q.push({rx, ry, stk + 1});
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            scanf("%d", &inp[y][x]);
            if (inp[y][x] == 3)
                마네킹.push_back({x, y});
            else if (inp[y][x] == 4)
                start = {x, y};
        }

    for (auto i : 마네킹)
        마네킹_탐색(i.first, i.second, 0);

    printf("%d", bfs());
    return 0;
}