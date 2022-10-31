/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, ans;
int inp[102][102];

int main()
{
    scanf("%d", &N);
    for (int i = 0, x, y; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        for (int ry = y; ry < y + 10; ry++)
            for (int rx = x; rx < x + 10; rx++)
                inp[ry][rx] = 1;
    }

    for (int y = 0; y < 100; y++)
        for (int x = 0; x < 100; x++)
            ans += inp[y][x];

    printf("%d", ans);

    return 0;
}
