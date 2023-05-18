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
stack<int> s;
int rest_length, min_value;
int A[100002];

signed main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    s.emplace(A[0]);

    for (int i = 1; i < N; i++)
    {
        if (s.top() < A[i])
        {
            ans = max(ans, ((long long)s.size() + 1) * min_value);
            while (!s.empty())
            {
                s.pop();
            }
        }
        min_value = A[i];

        s.emplace(A[i]);

        ans = max(ans, (long long)s.size() * min_value);
    }

    printf("%lld", ans);

    return 0;
}