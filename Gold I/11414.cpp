/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int A, B, a, b, ans, tmp, val = LONG_LONG_MAX;

signed main()
{
    scanf("%d %d", &a, &b);

    A = max(a, b);
    B = min(a, b);

    if (A == B)
    {
        printf("1");
        return 0;
    }

    vector<int> divisors;

    int car = A - B;
    int i = 1;
    for (; i * i <= car; i++)
    {
        if (car % i == 0)
        {
            divisors.emplace_back(i);
            divisors.emplace_back(car / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    for (auto d : divisors)
    {
        int r = A % d;
        r = d - r;
        int AA = A + r, BB = B + r;
        int tmp = AA * (BB / d);
        if (tmp < val)
        {
            val = tmp;
            ans = r;
        }
    }

    printf("%lld", ans);

    return 0;
}
