#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int chk[11];
int orgin_inp[11][11];
int inp[11][11];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

void change(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= 10 || ry < 0 || ry >= 10)
            continue;

        inp[ry][rx] = !inp[ry][rx];
    }
}

void dfs(int idx)
{
    if (idx == 10)
    {
        copy(&orgin_inp[0][0], &orgin_inp[11][11], &inp[0][0]);
        int cnt = 0;
        for (int x = 0; x < 10; x++)
        {
            if (chk[x])
            {
                cnt++;
                change(x, 0);
            }
        }

        for (int y = 1; y < 10; y++)
            for (int x = 0; x < 10; x++)
                if (inp[y - 1][x])
                {
                    cnt++;
                    change(x, y);
                }

        for (int y = 0; y < 10; y++)
            for (int x = 0; x < 10; x++)
                if (inp[y][x])
                    return;

        ans = min(ans, cnt);
        return;
    }
    chk[idx] = 0;
    dfs(idx + 1);
    chk[idx] = 1;
    dfs(idx + 1);
}

int main()
{
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
        {
            char tmp;
            scanf(" %1c", &tmp);
            orgin_inp[y][x] = (tmp == 'O');
        }
    dfs(0);
    if (ans == INT_MAX)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}