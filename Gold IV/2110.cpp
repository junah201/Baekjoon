/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, C;
vector<int> home;

bool is_allow(int key)
{
    int last = home[0];
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (home[i] - last >= key)
        {
            last = home[i];
            cnt++;
        }
    }

    if (cnt >= C)
        return true;
    return false;
}

int bs()
{
    int low = 1;
    int high = 1000000000;
    int mid;

    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (is_allow(mid))
        {
            low = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &N, &C);
    home.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &home[i]);

    sort(all(home));

    printf("%lld", bs());

    return 0;
}