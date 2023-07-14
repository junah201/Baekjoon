/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int n = 0, result = 0;

signed main()
{
    scanf("%lld", &n);

    for (int i = 1; i <= n; i *= 10)
        result += n - i + 1;

    printf("%lld", result);
}