// 12865 평범한 배낭
// https://www.acmicpc.net/source/39792755

#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<pair<int, int>> obj;
vector<int> DP;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, w, v; i < N; i++)
    {
        scanf("%d %d", &w, &v);
        if (w > M)
            continue;
        obj.emplace_back(w, v);
    }
    N = obj.size();
    DP.resize(M + 1, 0);
    for (int idx = 0; idx < N; idx++)
    {
        int w = obj[idx].first;
        int v = obj[idx].second;
        for (int size = M; size >= 0; size--)
        {
            if (w > size)
                continue;
            DP[size] = max(DP[size], DP[size - w] + v);
        }
    }
    for (int i = 1; i <= M; i++)
        ans = max(ans, DP[i]);
    printf("%d", ans);
    return 0;
}