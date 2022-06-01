#include <bits/stdc++.h>
using namespace std;

int N, ans = INT_MAX;
bool chk[18];
bool orgin_inp[18][18];
bool inp[18][18];

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void change(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= N || ry < 0 || ry >= N)
            continue;

        inp[ry][rx] = !inp[ry][rx];
    }
}

void dfs(int idx)
{
    if (idx == N)
    {
        copy(&orgin_inp[0][0], &orgin_inp[N][N], &inp[0][0]);
        int cnt = 0;
        for (int x = 0; x < N; x++)
            if (chk[x])
            {
                cnt++;
                change(x, 0);
            }

        for (int y = 1; y < N; y++)
            for (int x = 0; x < N; x++)
                if (inp[y - 1][x])
                {
                    cnt++;
                    change(x, y);
                }

        for (int x = 0; x < N; x++)
            if (inp[N - 1][x])
                return;

        ans = min(ans, cnt);
        return;
    }
    chk[idx] = true;
    dfs(idx + 1);
    chk[idx] = false;
    dfs(idx + 1);
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%1d", &orgin_inp[y][x]);

    dfs(0);

    if (ans == INT_MAX)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}