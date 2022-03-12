// 2718 타일 채우기
// https://www.acmicpc.net/source/40336654

#include <bits/stdc++.h>
using namespace std;

int T, N;
int DP[10000] = {1, 1, 5};

int get(int idx)
{
    if (idx < 0)
        return 0;
    if (!DP[idx])
    {
        DP[idx] = 4 * get(idx - 2) + 1 * get(idx - 1);

        for (int i = idx - 4; i >= 0; i -= 2)
            DP[idx] += 3 * get(i);
        for (int i = idx - 3; i >= 0; i -= 2)
            DP[idx] += 2 * get(i);
    }
    return DP[idx];
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        printf("%d\n", get(N));
    }
    return 0;
}