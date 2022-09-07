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
vector<vector<pair<int, int>>> graph(5002);

int bfs(int start, int k)
{
    int ans = 0;

    vector<int> check(N + 1, 0);
    queue<pair<int, int>> q;

    check[start] = 1;
    for (auto [idx, dis] : graph[start])
    {
        check[idx] = 1;
        q.emplace(idx, dis);
    }

    while (!q.empty())
    {
        auto [idx, dis] = q.front();
        q.pop();

        if (dis >= k)
        {
            ans++;
            dprintf("%d %d\n", idx, dis);
            for (auto [nidx, ndis] : graph[idx])
            {
                if (check[nidx])
                    continue;

                check[nidx] = 1;
                q.emplace(nidx, min(k, ndis));
            }
        }
    }

    return ans;
}

int main()
{
    scanf("%d %d", &N, &Q);

    for (int i = 0, p, q, r; i < N - 1; i++)
    {
        scanf("%d %d %d", &p, &q, &r);
        graph[q].emplace_back(p, r);
        graph[p].emplace_back(q, r);
    }

    for (int i = 0, k, v; i < Q; i++)
    {
        scanf("%d %d", &k, &v);
        printf("%d\n", bfs(v, k));
    }

    return 0;
}