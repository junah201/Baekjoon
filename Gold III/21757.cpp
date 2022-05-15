#include <bits/stdc++.h>
using namespace std;

long long N, div_value;
long long inp[100002];
long long sum[100002];
long long DP[100002];

int main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &inp[i]);
    sum[0] = inp[0];
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + inp[i];

    // 누적합 4의 배수가 아닌 경우
    if (sum[N - 1] % 4 != 0)
    {
        printf("0");
        return 0;
    }

    // 누적합 == 0
    if (sum[N - 1] == 0)
    {
        long long cnt = -1;
        for (int i = 0; i < N; i++)
            if (sum[i] == 0)
                cnt++;

        printf("%lld", cnt * (cnt - 1) * (cnt - 2) / 6);
        return 0;
    }

    div_value = sum[N - 1] / 4;

    for (int i = 0; i < N; i++)
    {
        if (sum[i] % div_value == 0)
        {
            if (sum[i] == div_value)
                DP[i] = 1;
            else
            {
                for (int j = 0; j < i; j++)
                    if (sum[j] == sum[i] - div_value)
                        DP[i] += DP[j];
            }
        }
    }

    printf("%lld", DP[N - 1]);
    return 0;
}