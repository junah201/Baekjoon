// 2476 주사위 게임

#include <bits/stdc++.h>
using namespace std;

int T, A, B, C, ans;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &A, &B, &C);
        if (A == B && B == C)
            ans = max(ans, 10000 + A * 1000);
        else if (A == B || B == C)
            ans = max(ans, 1000 + B * 100);
        else if (A == C)
            ans = max(ans, 1000 + A * 100);
        else
            ans = max(ans, max(A, max(B, C)) * 100);
    }
    printf("%d", ans);
    return 0;
}