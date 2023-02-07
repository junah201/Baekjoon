/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, ans, ans_idx;
vector<int> inp, DP;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        inp.emplace_back(tmp);
    }
    DP.resize(N + 2, 1);
    for (int i = 0; i < N; i++)
    {
        DP[i] = inp[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (inp[i] <= inp[j])
                continue;

            if (DP[i] < DP[j] + inp[i])
            {
                DP[i] = DP[j] + inp[i];
            }
        }
        if (DP[i] > ans)
        {
            ans = max(ans, DP[i]);
            ans_idx = i;
        }
    }

    printf("%d", ans);
    return 0;
}