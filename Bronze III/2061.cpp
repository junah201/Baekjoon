#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, L;

int main()
{
    scanf("%lld %lld", &K, &L);
    for (ll i = 2; i < L; i++)
        if (K % i == 0)
        {
            printf("BAD %lld", i);
            return 0;
        }
    printf("GOOD");
    return 0;
}