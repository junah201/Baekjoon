#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> graph;
vector<int> p;

double ans;

vector<pair<double, pair<int, int>>> q;

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
    graph.resize(N + 2);

    for (int i = 0; i <= N; i++)
        p.push_back(i);

    for (int i = 1, a, b; i <= N; i++)
        scanf("%d %d", &graph[i].first, &graph[i].second);

    for (int i = 0, a, b; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        uni(a, b);
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            long long dx = graph[i].first - graph[j].first;
            long long dy = graph[i].second - graph[j].second;
            q.push_back(make_pair(sqrt(dx * dx + dy * dy), make_pair(i, j)));
        }

    sort(q.begin(), q.end());

    for (int i = 0; i < q.size(); i++)
    {
        int a = q[i].second.first, b = q[i].second.second;
        if (fin(a) != fin(b))
        {
            ans += q[i].first;
            uni(a, b);
        }
    }

    printf("%.2lf", ans);
    return 0;
}