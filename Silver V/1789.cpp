/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N;

signed main()
{
    scanf("%lld", &N);
    int a = 1;
    while (N >= a)
    {
        N -= a;
        a += 1;
    }
    printf("%lld", a - 1);
    return 0;
}