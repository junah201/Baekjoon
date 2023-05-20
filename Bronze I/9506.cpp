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

int T, N;

void solve(int N)
{
    int tmp_sum = 1;
    vector<int> A;
    A.emplace_back(1);
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i != 0)
            continue;

        if (i * i == N)
        {
            A.emplace_back(i);
            tmp_sum += i;
        }
        else
        {
            A.emplace_back(i);
            A.emplace_back(N / i);
            tmp_sum += i + (N / i);
        }
    }

    if (tmp_sum != N)
    {
        printf("%lld is NOT perfect.\n", N);
        return;
    }

    printf("%lld = ", N);
    sort(A.begin(), A.end());
    printf("%lld", A[0]);
    for (size_t i = 1; i < A.size(); i++)
    {
        printf(" + %lld", A[i]);
    }
    printf("\n");
}

signed main()
{
    while (true)
    {
        scanf("%lld", &N);
        if (N == -1)
            break;

        solve(N);
    }
    return 0;
}