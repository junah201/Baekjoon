/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, Q;
stack<tuple<int, int, int>> query;
stack<bool> ans;
vector<int> p, graph;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    p[fin(a)] = fin(b);
}

int main()
{
    scanf("%d %d", &N, &Q);
    graph.resize(N + 2);
    p.resize(N + 2);
    for (int i = 2, tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        graph[i] = tmp;
    }
    for (int i = 0; i < Q + N - 1; i++)
    {
        int type;
        scanf("%d", &type);
        // 간선 자르기
        if (type == 0)
        {
            int b;
            scanf("%d", &b);
            query.emplace(type, b, -1);
        }
        // 연결 확인
        else
        {
            int c, d;
            scanf("%d %d", &c, &d);
            query.emplace(type, c, d);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
    }

    while (!query.empty())
    {
        auto [type, a, b] = query.top();
        query.pop();

        // 간선 붙이기
        if (type == 0)
        {
            // 부모 : graph[a]
            uni(a, graph[a]);
        }
        // 연결 확인
        else
        {
            if (fin(a) == fin(b))
                ans.emplace(1);
            else
                ans.emplace(0);
        }
    }

    while (!ans.empty())
    {
        if (ans.top())
            printf("YES\n");
        else
            printf("NO\n");
        ans.pop();
    }
    return 0;
}
