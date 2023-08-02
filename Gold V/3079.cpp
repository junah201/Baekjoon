/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M;
vector<int> cost;

int get_cnt(int num)
{
    int res = 0;

    for (int i = 0; i < N; i++)
    {
        res += num / cost[i];
        if (res >= M)
            return res;
    }

    return res;
}

int bs()
{
    int low = 1;
    int ans;
    int high = ans = 1000000000000000001LL;
    int mid, cnt;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cnt = get_cnt(mid);

        if (cnt >= M)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    cost.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &cost[i]);
    }

    printf("%lld", bs());

    return 0;
}