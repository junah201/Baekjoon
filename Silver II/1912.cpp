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
vector<int> DP;

signed main()
{
    scanf("%lld", &N);
    DP.resize(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%lld", &num);
        if (i == 0)
        {
            ans = num;
            DP[i] = max(num, (long long)(0));
        }
        else
        {
            DP[i] = max(DP[i - 1] + num, (long long)(0));
            ans = max(ans, DP[i]);
        }
    }

    printf("%lld", ans);

    return 0;
}