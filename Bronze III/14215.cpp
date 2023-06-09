/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> a(3);

signed main()
{
    scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
    sort(a.begin(), a.end());
    while (a[2] >= a[1] + a[0])
    {
        a[2]--;
    }
    printf("%lld", a[0] + a[1] + a[2]);
    return 0;
}