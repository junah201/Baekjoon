/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int T;

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int solve()
{
    int N, W;
    scanf("%d %d", &N, &W);
    vector<vector<int>> area(2);

    for (int y = 0, tmp; y < 2; y++)
        for (int x = 0; x < N; x++)
        {
            scanf("%d", &tmp);
            area[y].emplace_back(tmp);
        }

    // 모두 안이어졌을 때

    // [0][0] 이랑 [0][N - 1] 이어졌을 때

    // [1][0] 이랑 [1][N - 1] 이어졌을 때

    // 두개 모두 이어졌을 때
}

int main()
{
    scanf("%d", &T);
    while (T--)
        printf("%d\n", solve());

    return 0;
}