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

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N + 2, 1);

    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%lld %lld", &tmp, &A[i]);
    }

    for (int i = 0; i < N + 1; i++)
    {
        while (!s.empty() && s.top() > A[i])
        {
            int oy = s.top();
            s.pop();

            while (!s.empty() && s.top() == oy)
                s.pop();

            ans++;
        }

        while (!s.empty() && s.top() == A[i])
            s.pop();

        s.emplace(A[i]);
    }

    printf("%lld\n", ans);

    return 0;
}