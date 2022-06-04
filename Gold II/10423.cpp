#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int ans;

int p[1002];
vector<pair<int, pair<int, int>>> v;

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
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        p[i] = i;
    for (int i = 0, x; i < K; i++)
    {
        scanf("%d", &x);
        p[x] = 0;
    }

    for (int i = 0, start, end, dis; i < M; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        v.push_back({dis, {start, end}});
    }

    sort(v.begin(), v.end());

    for (auto [dis, tmp] : v)
    {
        auto [start, end] = tmp;
        if (fin(start) != fin(end))
        {
            ans += dis;
            uni(start, end);
        }
    }

    printf("%d", ans);
    return 0;
}