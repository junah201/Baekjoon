// 2643 색종이 올려 놓기
// https://www.acmicpc.net/source/40372194

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int x;
    int y;
} inp[102];

int N, DP[102], ans;

int get(int idx)
{
    if (!DP[idx])
    {
        for (int i = 0; i < N; i++)
        {
            if (idx == i)
                continue;
            if ((inp[idx].x >= inp[i].x && inp[idx].y >= inp[i].y) || (inp[idx].x >= inp[i].y && inp[idx].y >= inp[i].x))
                DP[idx] = max(DP[idx], get(i) + 1);
        }
    }
    return DP[idx];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &inp[i].x, &inp[i].y);
    for (int i = 0; i < N; i++)
        ans = max(ans, get(i));
    printf("%d", ans + 1);
    return 0;
}