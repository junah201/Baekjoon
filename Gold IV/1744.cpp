/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int N;
    scanf("%lld", &N);
    priority_queue<int, vector<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%lld", &tmp);
        if (tmp > 0)
            pq1.emplace(tmp);
        else
            pq2.emplace(tmp);
    }

    int ans = 0;

    while (pq1.size() > 1)
    {
        int top1 = pq1.top();
        pq1.pop();
        int top2 = pq1.top();
        pq1.pop();

        ans += max(top1 * top2, top1 + top2);
    }

    if (!pq1.empty())
    {
        ans += pq1.top();
        pq1.pop();
    }

    while (pq2.size() > 1)
    {
        int top1 = pq2.top();
        pq2.pop();
        int top2 = pq2.top();
        pq2.pop();

        ans += max(top1 * top2, top1 + top2);
    }

    if (!pq2.empty())
    {
        ans += pq2.top();
        pq2.pop();
    }

    printf("%lld", ans);

    return 0;
}