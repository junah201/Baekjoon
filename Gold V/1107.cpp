#include <bits/stdc++.h>
using namespace std;

int N, M, A[10], tmp;
queue<pair<int, int>> q;
vector<int> visited;

int bfs()
{
    q.emplace(100, 0);
    visited[100] = 1;
    while (!q.empty())
    {
        auto [cur, time] = q.front();
        q.pop();

        printf("%d %d\n", cur, time);

        if (cur == N)
            return time;

        for (int i = 0; i <= 9; i++)
        {
            if (A[i])
                continue;
            if (!visited[cur + i] && cur + i < N + 10)
            {
                visited[cur + i] = 1;
                q.emplace(cur + i, time + 1);
            }
            if (!visited[cur - i] && cur - i >= 0)
            {
                visited[cur - i] = 1;
                q.emplace(cur - i, time + 1);
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &N);
    if (N <= 100)
        visited.resize(101 + 10);
    else
        visited.resize(N + 1 + 10);
    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &tmp);
        A[tmp] = 1;
    }
    printf("%d", bfs());
    return 0;
}