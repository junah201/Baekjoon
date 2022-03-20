// 13302 리조트

#include <bits/stdc++.h>
#define MAX 987654321;
using namespace std;

int N, M, day[102], ans = MAX;
int DP[102][50];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, tmp; i < M; i++)
    {
        scanf("%d", &tmp);
        day[tmp] = 1;
    }
    // 초기화
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 50; j++)
            DP[i][j] = MAX;

    for (int i = 1; i < 50; i++)
        DP[0][i] = MAX;
    // 날짜
    for (int i = 1; i <= N; i++)
    {
        // 쿠폰 개수
        for (int j = 0; j < 50; j++)
        {
            // 1일권
            DP[i][j] = min(DP[i][j], DP[i - 1][j] + 10000);
            // 3일권
            if (i >= 3 && j >= 1)
                DP[i][j] = min(DP[i][j], DP[i - 3][j - 1] + 25000);
            // 5일권
            if (i >= 5 && j >= 2)
                DP[i][j] = min(DP[i][j], DP[i - 5][j - 2] + 37000);
            // 쿠폰
            if (j <= 46)
                DP[i][j] = min(DP[i][j], DP[i - 1][j + 3]);
            // 안가도 되는 날
            if (day[i])
                DP[i][j] = min(DP[i][j], DP[i - 1][j]);
        }
    }

    for (int i = 0; i < 50; i++)
        ans = min(ans, DP[N][i]);
    printf("%d", ans);
    return 0;
}