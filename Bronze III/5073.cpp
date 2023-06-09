/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    while (true)
    {
        int A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        if (A == 0 && B == 0 && C == 0)
            break;

        if (A + B + C <= max({A, B, C}) * 2)
            printf("Invalid\n");
        else if (A == B && B == C)
            printf("Equilateral\n");
        else if (A == B || B == C || C == A)
            printf("Isosceles\n");
        else
            printf("Scalene\n");
    }
    return 0;
}
