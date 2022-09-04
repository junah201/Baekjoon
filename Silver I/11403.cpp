#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF (ll)999999999999
#define mod (ll)1000000007
#define amod (ll)998244353
#define all(v) (v).begin(), (v).end()

int N;
int graph[102][102];
int is_visited[102][102];

void dfs(int start, int idx)
{
    if (is_visited[start][idx])
        return;
    is_visited[start][idx] = 1;
    for (int next = 0; next < N; next++)
    {
        if (is_visited[start][next])
            continue;
        if (graph[idx][next])
        {
            dfs(start, next);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%d", &graph[y][x]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int idx = 0; idx < N; idx++)
            if (graph[i][idx])
            {
                dfs(i, idx);
            }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            printf("%d ", is_visited[y][x]);
        }
        printf("\n");
    }
    return 0;
}