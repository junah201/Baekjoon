/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    vector<int> bits, bits_sum;

    int tmp = 0;

    for (int i = 0; i <= 20; i++)
    {
        bits.emplace_back(1 << i);
        tmp = tmp | 1 << i;
        bits_sum.emplace_back(tmp);
        printf("%lld ", bits[i]);
    }

    int A, B;
    scanf("%lld", &A, &B);
    vector<int> sum(B + 1, 0);

    printf("\n");
    for (int i = 1; i <= B; i++)
    {
        sum[i] = sum[i - 1];
        for (int j = 0; j <= 20; j++)
        {
            printf("%lld %lld : %lld\n", i, j, bits[j] & i);
            sum[i] += (int)((bits[j] & i) != 0);
        }
        printf("= %lld : %lld\n", i, sum[i]);
    }

    printf("%lld", sum[B] - sum[A - 1]);

    return 0;
}

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

signed main()
{
    scanf("%lld", &N);
    return 0;
}