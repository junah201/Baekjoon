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

int N, K, num, mid, ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> high;
priority_queue<pair<int, int>, vector<pair<int, int>>> low;

signed main()
{
    scanf("%lld %lld", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &num);
        if (high.size() == low.size())
        {
            // low에 삽입
            if (low.empty())
            {
                low.emplace(num);
            }
            else
            {
                if (high.top() < num)
                {
                    low.emplace(high.top());
                    high.pop();
                    high.emplace(num);
                }
                else
                {
                    low.emplace(num);
                }
            }
        }
        else
        {
            if (low.top() > num)
            {
                high.emplace(low.top());
                low.pop();
                low.emplace(num);
            }
            else
            {
                high.emplace(num);
            }
        }

        while (true)
        {
            auto [mid, idx] = low.top();

            if (idx >= i - K)
                break;
        }

        if (i >= K)
            ans += mid;
    }

    printf("%lld", ans);

    return 0;
}