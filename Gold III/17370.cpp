// 17370 육각형 우리 속의 개미
// https://www.acmicpc.net/source/40371837

#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int inp[200][200];

int dx[2][3] = {{1, -1, 0}, {1, -1, 0}};
int dy[2][3] = {{0, 0, 1}, {0, 0, -1}};

void dfs(int idx, int x, int y, int orgin_x, int orgin_y)
{
    if (idx == N + 1)
    {
        if (inp[y][x])
            cnt++;
        return;
    }
    if (inp[y][x])
        return;
    inp[y][x] = 1;
    int t;
    if ((x % 2 == 1 && y % 2 == 1) || (x % 2 == 0 && y % 2 == 0))
        t = 0;
    else
        t = 1;
    for (int i = 0; i < 3; i++)
    {
        int rx = x + dx[t][i];
        int ry = y + dy[t][i];

        if (rx == orgin_x && ry == orgin_y)
            continue;
        dfs(idx + 1, rx, ry, x, y);
    }
    inp[y][x] = 0;
}

int main()
{
    scanf("%d", &N);
    inp[101][100] = 1;
    dfs(1, 100, 100, 100, 101);
    printf("%d", cnt);
    return 0;
}