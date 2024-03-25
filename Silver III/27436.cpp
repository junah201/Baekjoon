/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
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

int N;
int K = 100000000;
vector<int> pibo;

int get()
{
    int left = 0;
    int right = K - 3;
    int mid = (left + right) / 2;
    int ans = INF;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (pibo[mid] > N)
        {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld", &N);
    pibo.resize(K + 1);
    if (N == 1)
    {
        printf("1");
    }

    N -= 1;

    pibo[0] = 1;
    for (int i = 2; i < K; i++)
    {
        pibo[i - 1] = i + pibo[i - 2];
    }
    for (int i = 0; i < K; i++)
    {
        pibo[i] = pibo[i] * 6;
        if (pibo[i] < 0)
        {
            printf("idx: %lld\n", i);
            return 0;
        }
    }

    printf("%lld\n", pibo[K - 2]);

    printf("%lld", get() + 2);

    return 0;
}

/*
1
6
12
18


*/