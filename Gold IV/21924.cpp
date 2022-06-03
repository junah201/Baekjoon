#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans;
int p[100002];
vector<pair<long long, pair<int, int>>> edges;

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
    if (a != b)
        p[a] = b;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++)
        p[i] = i;
    for (int i = 1, start, end, dis; i <= M; i++)
    {
        scanf("%lld %d %d", &start, &end, &dis);
        edges.push_back(make_pair(dis, make_pair(start, end)));
        ans += dis;
    }

    sort(edges.begin(), edges.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
         { return a.first < b.first; });

    for (auto i : edges)
    {
        int dis = i.first;
        int start = i.second.first;
        int end = i.second.second;
        if (fin(start) != fin(end))
        {
            ans -= dis;
            uni(start, end);
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (fin(1) != fin(i))
        {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", ans);
    return 0;
}