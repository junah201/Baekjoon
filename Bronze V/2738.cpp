/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int X, Y, tmp;

int ans[102][102];

int main()
{
    scanf("%d %d", &Y, &X);

    for (int i = 0; i < 2; i++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                scanf("%d", &tmp);
                ans[y][x] += tmp;
            }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
            printf("%d ", ans[y][x]);
        printf("\n");
    }

    return 0;
}