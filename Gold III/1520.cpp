/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int X, Y, ans;
int inp[502][502];
bool DP[502][502][4];

int DP2[502][502];
bool isinputed[502][502];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int dir)
{
    DP[y][x][dir] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > X || ny < 1 || ny > Y)
            continue;

        if (inp[y][x] <= inp[ny][nx])
            continue;

        if (DP[ny][nx][i])
            continue;

        dfs(nx, ny, i);
    }
}

int bfs()
{
    queue<pair<int, int>> q;

    q.emplace(1, 1);
    DP2[1][1] = 1;
    isinputed[1][1] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (!DP[y][x][0] && !DP[y][x][1] && !DP[y][x][2] && !DP[y][x][3])
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // printf("= (%d %d)\n", nx, ny);

                if (nx < 1 || nx > X || ny < 1 || ny > Y)
                    continue;

                if (!DP[ny][nx][i])
                    continue;

                DP[ny][nx][i] = false;
                DP2[ny][nx] += DP2[y][x];

                if (!isinputed[ny][nx])
                {
                    q.emplace(nx, ny);
                    isinputed[ny][nx] = true;
                }
            }
        }
        else
        {
            q.emplace(x, y);
        }
    }
    return DP2[Y][X];
}

int main()
{
    scanf("%d %d", &Y, &X);

    for (int y = 1; y <= Y; y++)
    {
        for (int x = 1; x <= X; x++)
        {
            scanf("%d", &inp[y][x]);
        }
    }

    dfs(1, 1, 0);

    DP[1][1][0] = false;

    printf("\n");
    for (int y = 1; y <= Y; y++)
    {
        for (int x = 1; x <= X; x++)
        {
            for (int i = 0; i < 4; i++)
            {
                printf("%d", DP[y][x][i]);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("%d", bfs());
    // for (int y = 1; y <= Y; y++)
    // {
    //     for (int x = 1; x <= X; x++)
    //     {
    //         printf("%d ", DP2[y][x]);
    //     }
    //     printf("\n");
    // }

    return 0;
}