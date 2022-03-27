// 18251 내 생각에 A번인 단순 dfs 문제가 이 대회에서 E번이 되어버린 건에 관하여 (Easy)

#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

lld N, ans = INT_MIN;
lld mx, my, tmp;
vector<lld> graph, x, y, idx_x;
lld inp[20][300000];

lld get_my(lld N)
{
    lld result = 0;
    while (N)
    {
        result++;
        N /= 2;
    }
    return result;
}

void get_x(lld idx)
{
    if (idx * 2 <= N)
        get_x(idx * 2);
    x[idx] = tmp++;
    if (idx * 2 + 1 <= N)
        get_x(idx * 2 + 1);
}

void get_y(lld idx, lld stk)
{
    y[idx] = stk;
    if (idx * 2 <= N)
        get_y(idx * 2, stk + 1);
    if (idx * 2 + 1 <= N)
        get_y(idx * 2 + 1, stk + 1);
}

int main()
{
    scanf("%lld", &N);
    graph.resize(N + 1);
    x.resize(N + 1);
    y.resize(N + 1);
    idx_x.resize(N + 1);

    mx = N;
    my = get_my(N);

    for (int i = 1; i <= N; i++)
        scanf("%lld", &graph[i]);

    tmp = 1;
    get_x(1);
    get_y(1, 1);

    for (int i = 1; i <= N; i++)
    {
        inp[y[i]][x[i]] = graph[i];
        idx_x[x[i]] = y[i];
    }

    for (lld y1 = 1, DP; y1 <= my; y1++)
    {
        for (lld y2 = 1; y2 <= y1; y2++)
        {
            DP = 0;
            for (lld tx = 1; tx <= mx; tx++)
            {
                if (idx_x[tx] <= y1 && idx_x[tx] >= y2)
                {
                    DP += inp[idx_x[tx]][tx];
                    ans = max(ans, DP);
                }
                if (DP < 0)
                    DP = 0;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}