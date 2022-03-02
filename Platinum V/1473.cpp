#include <bits/stdc++.h>
using namespace std;

int N, M;
char inp[10][10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct info
{
    int x, y, time;
};

int bfs()
{
    queue<info> q;
    q.push({0, 0, 0});

    while (!q.empty())
    {
        auto [x, y, time] = q.front();
        q.pop();

        if (x == M - 1 && y == N - 1)
            return time;

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++)
        scanf("%s", inp[y]);
    printf("%d", bfs());
    return 0;
}