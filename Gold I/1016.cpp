#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mn, mx, ans;
int num[1000002];

int main()
{
    scanf("%lld %lld", &mn, &mx);
    for (ll i = 2; i * i <= mx; i++)
    {
        for (ll j = mn / (i * i); j * i * i <= mx; j += 1)
        {
            if (i * i * j - mn < 0)
                continue;
            num[j * i * i - mn] = 1;
        }
    }
    for (ll i = mn; i <= mx; i++)
        ans += !num[i - mn];
    printf("%lld", ans);
    return 0;
}