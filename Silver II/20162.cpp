#include <bits/stdc++.h>
using namespace std;

int N, ans = -INT_MAX;
int inp[1002];
int DP[1002];

// DP[i] 에는 i번째 inp를 선택했을 때의 최대값

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &inp[i]);

    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (inp[j] < inp[i])
                tmp = max(tmp, DP[j]);
        }
        DP[i] = tmp + inp[i];
        ans = max(ans, DP[i]);
    }
    printf("%d", ans);
}