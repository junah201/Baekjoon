// 1799 비숍
// https://www.acmicpc.net/source/40436809

#include <bits/stdc++.h>
using namespace std;

int N, ans[2];
int inp[12][12];
int l[20];
int r[20];

void dfs(int idx, int x, int y, int color)
{
    if (x >= N)
    {
        if (x % 2 == 0)
            x = 1;
        else
            x = 0;
        y++;
    }
    if (y >= N)
    {
        ans[color] = max(ans[color], idx);
        return;
    }

    if (inp[y][x] && !l[y - x + N - 1] && !r[y + x])
    {
        l[y - x + N - 1] = r[y + x] = 1;
        dfs(idx + 1, x + 2, y, color);
        l[y - x + N - 1] = r[y + x] = 0;
    }
    dfs(idx, x + 2, y, color);
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &inp[y][x]);

    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    printf("%d", ans[0] + ans[1]);
    return 0;
}