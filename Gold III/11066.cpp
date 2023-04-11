/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> file, presum;
vector<vector<int>> DP;

int get_value(int start, int end)
{
    if (start == end)
        return file[start];

    pair<int, int> p = {start, end};

    if (DP[start][end] == 0)
    {
        int result = INT_MAX;

        int tmpsum = presum[end + 1] - presum[start];

        for (int i = start; i < end; i++)
            result = min(result, get_value(start, i) + get_value(i + 1, end) + tmpsum);

        DP[start][end] = result;
    }

    return DP[start][end];
}

void solve()
{
    scanf("%d", &N);
    file.clear();
    DP.clear();
    DP.resize(N + 2, vector<int>(N + 2));

    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        file.emplace_back(tmp);
    }

    presum.resize(N + 2);
    presum[0] = 0;
    for (int i = 1; i <= N; i++)
        presum[i] = presum[i - 1] + file[i - 1];

    int ans = INT_MAX;

    for (int i = 0; i < N - 1; i++)
        ans = min(ans, get_value(0, i) + get_value(i + 1, N - 1));

    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &T);
    while (T--)
        solve();

    return 0;
}