/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int A, B, a, b, ans, ans2, tmp;

int main()
{
    scanf("%d %d", &a, &b);

    A = max(a, b);
    B = min(a, b);

    if (A - B > B)
    {
        printf("%d", A - B - B);
        return 0;
    }

    for (int i = B; i > 0; i--)
    {
    }

    printf("%d", ans2);

    return 0;
}

/*
lcm(A + N, B + N);
lcm(A - B, B + N);

A = 10   B = 4

lcm(6, 4 + N)

A = 10   B = 6

lcm(4, 6 + N)

*/