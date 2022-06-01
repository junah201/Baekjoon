#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A, B, C;

ll f(int p)
{
    if (p == 1)
        return A;
    ll tmp = f(p / 2);
    if (p % 2)
        return (((tmp * tmp) % C) * A) % C;
    else
        return (tmp * tmp) % C;
}

int main()
{
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", f(B) % C);
    return 0;
}
