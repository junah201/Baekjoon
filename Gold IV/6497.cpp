#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans;
int p[200002];
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
    while (true)
    {
        memset(p, 0, sizeof(p));
        ans = 0;
        edges.erase(edges.begin(), edges.end());
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0)
            break;
        for (int i = 0; i <= N; i++)
            p[i] = i;
        for (int i = 0, start, end, dis; i < M; i++)
        {
            scanf("%d %d %d", &start, &end, &dis);
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

        for (int i = 1; i < N; i++)
        {
            if (fin(0) != fin(i))
            {
                printf("-1");
                continue;
            }
        }
        printf("%d\n", ans);
    }
}