/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int N;
ll ans, tmp;
vector<ll> dis, cost;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &tmp);
        dis.emplace_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &tmp);
        cost.emplace_back(tmp);
    }

    for (int i = 1; i < N; i++)
        cost[i] = min(cost[i], cost[i - 1]);

    for (int i = 0; i < N - 1; i++)
    {
        ans += cost[i] * dis[i];
    }

    printf("%lld", ans);

    return 0;
}