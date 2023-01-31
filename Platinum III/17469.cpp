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

int N, Q;
stack<tuple<int, int, int>> query;
vector<int> graph;
vector<set<int>> colors;
vector<int> p;
stack<int> ans;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void marge(int a, int b)
{
    int tmp_a = fin(a);
    int tmp_b = fin(b);

    if (tmp_a == tmp_b)
        return;

    if (colors[tmp_a].size() > colors[tmp_b].size())
    {
        a = tmp_a;
        b = tmp_b;
    }
    else
    {
        a = tmp_b;
        b = tmp_a;
    }

    p[b] = a;

    for (auto i = colors[b].begin(); i != colors[b].end(); i++)
        colors[a].insert(*i);
    colors[b].clear();
}

int main()
{
    scanf("%d %d", &N, &Q);

    graph.resize(N + 2);
    colors.resize(N + 2);
    p.resize(N + 2);

    graph[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        scanf("%d", &graph[i]);
    }

    for (int i = 1, tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        colors[i].insert(tmp);
        p[i] = i;
    }

    for (int i = 0; i < Q + N - 1; i++)
    {
        int x, a;
        scanf("%d %d", &x, &a);
        query.emplace(x, a, i);
    }

    while (!query.empty())
    {
        auto [x, a, idx] = query.top();
        query.pop();

        // printf("%d %d %d\n", x, a, idx);

        if (x == 1)
        {
            marge(graph[a], a);
        }
        else
        {
            ans.emplace(colors[fin(a)].size());
        }
    }

    while (!ans.empty())
    {
        printf("%d\n", ans.top());
        ans.pop();
    }

    return 0;
}