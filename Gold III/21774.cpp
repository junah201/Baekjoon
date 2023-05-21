/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, Q;
vector<vector<int>> logs(7);

pair<int, int> get_range(int level, int start_time, int end_time)
{
    int start_idx = upper_bound(logs[level].begin(), logs[level].end(), start_time) - logs[level].begin();
    int end_idx = lower_bound(logs[level].begin(), logs[level].end(), end_time) - logs[level].begin();

    return {start_idx, end_idx};
}

signed main()
{
    scanf("%lld %lld", &N, &Q);

    int year, month, day, h, m, s, level;
    int start_time, end_time, ans = 0;
    while (N--)
    {
        scanf("%lld-%lld-%lld %lld:%lld:%lld#%lld", &year, &month, &day, &h, &m, &s, &level);
        for (int i = 1; i <= level; i++)
        {
            logs[i].emplace_back(year * 10000000000 + month * 100000000 + day * 1000000 + h * 10000 + m * 100 + s);
        }
    }

    while (Q--)
    {
        scanf("%lld-%lld-%lld %lld:%lld:%lld#", &year, &month, &day, &h, &m, &s);
        start_time = year * 10000000000 + month * 100000000 + day * 1000000 + h * 10000 + m * 100 + s;
        scanf("%lld-%lld-%lld %lld:%lld:%lld", &year, &month, &day, &h, &m, &s, &level);
        end_time = year * 10000000000 + month * 100000000 + day * 1000000 + h * 10000 + m * 100 + s;
        scanf("#%lld", &level);

        if (logs[level].size() == 0)
        {
            printf("%lld\n", 0);
            continue;
        }

        int up_idx = upper_bound(logs[level].begin(), logs[level].end(), end_time) - logs[level].begin();
        int down_idx = lower_bound(logs[level].begin(), logs[level].end(), start_time) - logs[level].begin();

        printf("%lld\n", up_idx - down_idx);
    }

    return 0;
}