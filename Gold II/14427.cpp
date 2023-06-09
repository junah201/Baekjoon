/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
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

signed main()
{
    int N;
    scanf("%lld", &N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
        pq.emplace(A[i], i);
    }
    int Q;
    scanf("%lld", &Q);
    while (Q--)
    {
        int oper;
        scanf("%lld", &oper);
        if (oper == 1)
        {
            int i, v;
            scanf("%lld %lld", &i, &v);

            A[i] = v;
            pq.emplace(A[i], i);
        }
        else
        {
            while (true)
            {
                auto [value, idx] = pq.top();
                if (A[idx] == value)
                {
                    printf("%lld\n", idx);
                    break;
                }
                pq.pop();
            }
        }
    }
    return 0;
}