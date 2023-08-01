/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, K;

int get_cnt(int num)
{
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        res += min(N, num / i);
    }
    return res;
}

int bs()
{
    int low = 1;
    int high = K;
    int ans = 0;
    int mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        int cnt = get_cnt(mid);

        if (cnt >= K)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &N, &K);

    printf("%lld", bs());

    return 0;
}