// 1059 좋은 구간
// https://www.acmicpc.net/source/39581586

#include <stdio.h>

int L, N;
int S[52];
int min = 0, max = 987654321;

int main()
{
    scanf("%d", &L);
    for (int i = 0; i < L; i++)
        scanf("%d", &S[i]);
    scanf("%d", &N);
    for (int i = 0; i < L; i++)
    {
        if (S[i] <= N && S[i] > min)
            min = S[i];
        if (S[i] >= N && S[i] < max)
            max = S[i];
    }
    if (min == N || max == N)
        printf("%d", 0);
    else
    {
        int cnt = 0;
        int low = min + 1;
        int high = N;
        while (low <= N && N <= high)
        {
            if (low != high)
                cnt++;
            if (high == max - 1)
                high = N, low++;
            else
                high++;
        }
        printf("%d", cnt);
    }
    return 0;
}