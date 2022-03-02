// 14651 걷다보니 신천역 삼 (Large)
// https://www.acmicpc.net/source/39848992

#include <bits/stdc++.h>
using namespace std;

int N;
long long DP[33335][3];

int main()
{
    DP[1][0] = 0;
    DP[1][1] = 1;
    DP[1][2] = 1;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 1000000009;
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 1000000009;
        DP[i][2] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 1000000009;
    }
    printf("%lld", DP[N][0]);
    return 0;
}