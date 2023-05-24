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

int T, N, max_N;
vector<int> A;
vector<char> is_prime;

signed main()
{
    scanf("%lld", &T);
    A.resize(T);

    for (int i = 0; i < T; i++)
    {
        scanf("%lld", &A[i]);
        max_N = max(max_N, A[i]);
    }

    is_prime.resize(max_N + 2, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= max_N; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j <= max_N; j += i)
        {
            is_prime[j] = false;
        }
    }

    for (auto i : A)
    {
        int ans = 0;
        for (int j = 2; j * 2 <= i; j++)
        {
            if (is_prime[j] && is_prime[i - j])
                ans++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}