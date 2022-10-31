/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M, idx = 1, ans;
char inp[1002][1002];
int id[1002][1002];

map<char, pair<int, int>> mp{
    {'U', {0, -1}},
    {'D', {0, 1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}};

int dfs(int x, int y, int idx)
{
    if (id[y][x] == idx)
        return 0;
    else if (id[y][x] != 0)
        return id[y][x];
    id[y][x] = idx;
    auto [dx, dy] = mp[inp[y][x]];
    return dfs(x + dx, y + dy, idx);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf(" %c", &inp[y][x]);

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            if (id[y][x])
                continue;
            if (!dfs(x, y, idx++))
                ans++;
        }
    printf("%d", ans);

    return 0;
}
