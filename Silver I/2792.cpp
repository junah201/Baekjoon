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

int N, M;
vector<int> sticks;

int get_cnt(int num)
{
    int res = 0;
    for (int i : sticks)
    {
        if (i % num == 0)
            res += i / num;
        else
            res += (i / num) + 1;
    }
    return res;
}

int bs()
{
    int low = 1;
    int high = INF / 2;
    int mid, ans = INF, cnt;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cnt = get_cnt(mid);

        if (cnt > M)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, mid);
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &M, &N);
    sticks.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &sticks[i]);
    }

    printf("%lld", bs());

    return 0;
}