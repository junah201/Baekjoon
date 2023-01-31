/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, Q;

priority_queue<tuple<int, int, int>> graph;
priority_queue<tuple<int, int, int>> query;
vector<int> root, ans, p_size;

int fin(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = fin(root[x]);
}

void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);

    if (a != b)
    {
        root[a] = b;
        p_size[b] += p_size[a];
    }
}

int main()
{
    scanf("%d %d", &N, &Q);
    root.resize(N + 2);
    ans.resize(Q + 2);
    p_size.resize(N + 2);

    for (int i = 1; i <= N; i++)
    {
        root[i] = i;
        p_size[i] = 1;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        graph.emplace(r, p, q);
    }
    for (int i = 0; i < Q; i++)
    {
        int k, v;
        scanf("%d %d", &k, &v);
        query.emplace(k, v, i);
    }

    while (!query.empty())
    {
        auto [k, v, idx] = query.top();
        query.pop();

        while (!graph.empty())
        {
            auto [r, p, q] = graph.top();

            if (r < k)
                break;

            uni(p, q);
            graph.pop();
        }

        ans[idx] = p_size[fin(v)] - 1;
    }

    for (int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);

    return 0;
}