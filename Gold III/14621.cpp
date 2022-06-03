#include <bits/stdc++.h>
using namespace std;

int N, M, ans, last;
int p[100002], gender[100002];
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
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        char tmp;
        scanf(" %c", &tmp);
        gender[i] = (tmp == 'M');
    }

    for (int i = 1, start, end, dis; i <= M; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        if (gender[start] != gender[end])
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
    for (int i = 1; i <= N; i++)
    {
        if (fin(1) != fin(i))
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d", ans);
    return 0;
}