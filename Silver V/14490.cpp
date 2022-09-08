/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M;

int main()
{
    scanf("%d:%d", &N, &M);
    printf("%d:%d\n", N / gcd(N, M), M / gcd(N, M));

    return 0;
}