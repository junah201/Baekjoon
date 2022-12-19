#include <bits/stdc++.h>
using namespace std;

int N, ans;
int inp[102][102];
int visited[102][102];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    if (visited[y][x])
        return;

    visited[y][x] = 1;

    if (inp[y][x] == -1)
        ans = 1;

    if (ans)
        return;

    for (int i = 0; i < 4; i++)
    {
        int rx = x + inp[y][x] * dx[i];
        int ry = y + inp[y][x] * dy[i];

        if (rx < 0 || ry < 0 || rx >= N || ry >= N)
            continue;

        dfs(rx, ry);
    }
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &inp[y][x]);

    dfs(0, 0);

    if (ans)
        printf("HaruHaru");
    else
        printf("Hing");
}