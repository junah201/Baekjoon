#include <bits/stdc++.h>
using namespace std;

int N, M, ans, last;
int p[100002];
vector<pair<int, pair<int, int>>> edges;

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
        scanf("%d %d %d", &start, &end, &dis);
        edges.push_back(make_pair(dis, make_pair(start, end)));
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
            ans += dis;
            uni(start, end);
        }
    }
    printf("%d", ans);
    return 0;
}