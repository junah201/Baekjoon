#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
int inp[1002][1002];
int p[1002];
vector<pair<int, pair<int, int>>> graph;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);

    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        for (int j = 0; j < N; j++)
            scanf("%d", &inp[i][j]);
    }

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            graph.push_back({inp[i][j], {i, j}});

    sort(graph.begin(), graph.end());

    for (auto i : graph)
    {
        auto [dis, tmp] = i;
        auto [start, end] = tmp;

        if (fin(start) != fin(end))
        {
            ans += dis;
            uni(start, end);
        }
    }
    printf("%lld", ans);
    return 0;
}