// 1309 동물원
// https://www.acmicpc.net/source/39793007

#include <bits/stdc++.h>
using namespace std;

int N;
int DP[100002][2];

int main()
{
    scanf("%d", &N);

    DP[1][0] = 1;
    DP[1][1] = 2;

    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
        DP[i][1] = (DP[i - 1][0] * 2 + DP[i - 1][1]) % 9901;
    }

    printf("%d", (DP[N][0] + DP[N][1]) % 9901);
}