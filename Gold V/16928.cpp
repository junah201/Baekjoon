#include <bits/stdc++.h>
using namespace std;

int N, M;
struct _obj
{
    int to;
    int type;
} obj[102];
int visited[102];

int bfs()
{
    queue<pair<int, int>> q;
    q.emplace(1, 0);

    while (!q.empty())
    {
        int idx = q.front().first, dis = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            if (idx + i == 100)
                return dis + 1;
            if (idx + i > 100)
                continue;
            if (visited[idx + i])
                continue;
            visited[idx + i] = 1;
            if (obj[idx + i].type == 's')
                q.emplace(obj[idx + i].to, dis + 1);
            else if (obj[idx + i].type == 'l')
                q.emplace(obj[idx + i].to, dis + 1);
            else
                q.emplace(idx + i, dis + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    while (N--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        obj[u].to = v;
        obj[u].type = 'l';
    }
    while (M--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        obj[u].to = v;
        obj[u].type = 's';
    }
    printf("%d", bfs());
    return 0;
}