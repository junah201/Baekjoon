/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;

signed main()
{
    scanf("%lld", &N);
    vector<tuple<int, int, int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        v.emplace_back(a, b, (b - a) * 2, (int)1);
    }

    sort(all(v));

    vector<tuple<int, int, int, int>> vv;

    auto [a, b, s, e] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto [na, nb, ns, ne] = v[i];
        printf("(%lld %lld, %lld) (%lld %lld, %lld)\n", a, b, s, na, nb, ns);

        // ㅁ ㅇ ㅇ ㅁ
        if (nb < b)
        {
            continue;
        }
        // ㅁ ㅇ ㅁ ㅇ
        if (b > na)
        {
            vv.emplace_back(a, na - 1, s, s - (na - 1 - a));
            a = na;
            b = nb;
            s = ns;
            e = ne;
        }
        // ㅁ ㅁ ㅇ ㅇ
        if (b < na)
        {
            vv.emplace_back(a, b, s, e);
            a = na;
            b = nb;
            s = ns;
            e = ne;
        }
    }
    vv.emplace_back(a, b, s, e);

    int ans = 0;

    printf("%lld\n\n", vv.size());

    for (auto k : vv)
    {
        auto [na, nb, ns, ne] = k;
        printf("%lld %lld %lld %lld : %lld\n", na, nb, ns, ne, (ns + ne) * (nb - na + 1) / 2);

        ans += (ns + ne) * (nb - na + 1) / 2;
    }

    printf("%lld", ans);

    return 0;
}
/*

ㅁ ㅇ ㅇ ㅁ
ㅁ ㅇ ㅁ ㅇ

2 3 4 5
5 4 3 2



*/