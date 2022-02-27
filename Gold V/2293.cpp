// 2293 동전 1

#include <stdio.h>

int N, K;
int coin[102];
int DP[10002];

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &coin[i]);
        if (coin[i] > K)
            continue;
        DP[coin[i]] = 0;
    }
    for (int idx = 0; idx < N; idx++)
    {
        if (coin[idx] > K)
            continue;
        DP[coin[idx]] += 1;
        for (int cost = 1; cost <= K; cost++)
        {
            if (coin[idx] > cost)
                continue;
            if (cost - coin[idx] > 0)
                DP[cost] += DP[cost - coin[idx]];
        }
    }
    printf("%d", DP[K]);
    return 0;
}