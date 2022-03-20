// 12015 가장 긴 증가하는 부분 수열 2

#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<int> DP;

int main()
{
    scanf("%d", &N);
    DP.resize(N + 2, INT_MAX);
    DP[0] = 0;
    for (int i = 1, idx, tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        idx = upper_bound(DP.begin(), DP.end(), tmp) - DP.begin();

        while (DP[idx] > tmp && DP[idx - 1] < tmp)
            DP[idx++] = tmp;
    }
    for (int i = 1; i <= N; i++)
        if (DP[i] != INT_MAX)
            ans = i;
    printf("%d", ans);
    return 0;
}