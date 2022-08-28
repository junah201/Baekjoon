#include <bits/stdc++.h>
using namespace std;

int N;
int inp[500002];
int DP[500002];

int get(int idx)
{
    DP[idx] = 0;
    for (int i = idx + 1; i < N; i++)
    {
        if (inp[idx] < inp[i])
        {
            if (DP[i] == -1)
            {
                DP[i] = get(i);
            }
            DP[idx] = DP[i] + 1;
            break;
        }
    }
    return DP[idx];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &inp[i]);
    }

    memset(DP, -1, sizeof(int) * 500002);

    for (int i = N - 1; i >= 0; i--)
    {
        get(i);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", DP[i]);
    }
    return 0;
}