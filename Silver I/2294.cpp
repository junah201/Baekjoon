// 2294 동전 2

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;
int coin[102];
int DP[100002];

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &coin[i]);
        DP[coin[i]] = 1;
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i - coin[j] > 0 && DP[i - coin[j]] && (DP[i] == 0 || DP[i] > DP[i - coin[j]] + 1))
                DP[i] = DP[i - coin[j]] + 1;
        }
    }
    if (DP[K] == 0)
        printf("%d", -1);
    else
        printf("%d", DP[K]);
    return 0;
}