// 1965  상자넣기
// https://www.acmicpc.net/source/39792919

#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<int> inp, DP;

int main()
{
    scanf("%d", &N);
    inp.resize(N);
    DP.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &inp[i]);
        DP[i] = 1;
        for (int j = 0; j < i; j++)
            if (inp[j] < inp[i])
                DP[i] = max(DP[i], DP[j] + 1);
    }
    for (int i = 0; i < N; i++)
        ans = max(ans, DP[i]);
    printf("%d", ans);
    return 0;
}