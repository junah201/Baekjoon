/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N, ans;
priority_queue<int, vector<int>, greater<int>> pq;

signed main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%lld", &tmp);
        pq.emplace(tmp);
    }

    while (pq.size() > 1)
    {
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();
        ans += top1 + top2;
        pq.emplace(top1 + top2);
    }

    printf("%lld", ans);

    return 0;
}