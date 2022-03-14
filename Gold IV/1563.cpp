// 1563 개근상
// https://www.acmicpc.net/source/40373702

#include <bits/stdc++.h>
using namespace std;

int N, ans;
int DP[1002][7];

int main()
{
    DP[0][0] = 1;
    DP[0][2] = 1;
    DP[0][3] = 1;

    scanf("%d", &N);
    for (int idx = 1; idx <= N; idx++)
    {
        DP[idx][0] = (DP[idx - 1][0] + DP[idx - 1][3] + DP[idx - 1][5]) % 1000000;
        DP[idx][1] = (DP[idx - 1][1] + DP[idx - 1][2] + DP[idx - 1][4] + DP[idx - 1][6]) % 1000000;
        DP[idx][2] = (DP[idx - 1][0] + DP[idx - 1][3] + DP[idx - 1][5]) % 1000000;
        DP[idx][3] = (DP[idx - 1][0]) % 1000000;
        DP[idx][4] = (DP[idx - 1][1] + DP[idx - 1][2]) % 1000000;
        DP[idx][5] = (DP[idx - 1][3]) % 1000000;
        DP[idx][6] = (DP[idx - 1][4]) % 1000000;
    }
    for (int i = 0; i < 7; i++)
        ans += DP[N - 1][i];

    printf("%d", ans % 1000000);
    return 0;
}

/*
마지막이 출석
0 :    지각 횟수 0
1 :    지각 횟수 1

마지막이 지각
2 :    지각횟수 1

마지막이 결석 1
3 :    지각 횟수 0
4 :    지각 횟수 1

마지막이 결석 2
5 :    지각 횟수 0
6 :    지각 횟수 1
*/