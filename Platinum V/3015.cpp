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

int N, ans;
int A[500002];
stack<pair<int, int>> s;

signed main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    s.emplace(A[0], 1);

    for (int i = 1; i < N; i++)
    {
        if (!s.empty() && s.top().first < A[i])
        {
            while (!s.empty() && s.top().first < A[i])
            {
                ans += s.top().second;
                s.pop();
            }
        }

        if (!s.empty() && s.top().first > A[i])
        {
            ans += 1;
        }
        else
        {
            if (!s.empty())
            {
                if (s.size() == 1)
                {
                    dprintf("=1\n");
                    ans += s.top().second;
                }
                else
                {
                    dprintf("=2 : %lld %lld\n", s.top().second, s.size());
                    ans += s.top().second + 1;
                }
            }
        }

        if (!s.empty() && s.top().first == A[i])
        {
            auto [value, cnt] = s.top();
            s.pop();
            s.emplace(value, cnt + 1);
        }
        else
        {
            s.emplace(A[i], 1);
        }

        if (!s.empty())
        {
            dprintf("(%d %d)\n", s.top().first, s.top().second);
        }
        else
        {
            dprintf("(-, -)\n");
        }
        dprintf("%lld %lld : %lld\n", i, s.size(), ans);
    }

    printf("%lld", ans);

    return 0;
}