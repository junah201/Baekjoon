/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int X, Y, Q;

signed main()
{
    scanf("%lld %lld %lld", &Y, &X, &Q);
    vector<vector<int>> ans(Y, vector<int>(X, 0));
    // 가로
    vector<int> row(X, 0);
    // 세로
    vector<int> col(Y, 0);

    while (Q--)
    {
        int oper, t, u;
        scanf("%lld %lld %lld", &oper, &t, &u);

        if (oper == 1)
        {
            col[t - 1] += u;
        }
        else if (oper == 2)
        {
            row[t - 1] += u;
        }
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            printf("%lld ", row[x] + col[y]);
        }
        printf("\n");
    }

    return 0;
}