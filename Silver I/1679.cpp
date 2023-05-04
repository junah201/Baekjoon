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

int N, K, A[1002];
vector<vector<int>> DP(2, vector<int>(200002, INT_MAX));

signed main()
{
    scanf("%lld", &N);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        pq.emplace(A[i], 1, A[i] % 2);
        DP[A[i] % 2][A[i]] = 1;
    }
    scanf("%lld", &K);

    for (int i = 2;; i++)
    {
        }

    for (int i = 1;; i++)
    {
        if (DP[i % 2][i] > K)
        {
            if (i % 2 == 1)
                printf("jjaksoon ");
            else if (i % 2 == 0)
                printf("holsoon ");
            printf("win at %lld", i);
            return 0;
        }
    }

    return 0;
}