/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double distanse = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double subtract = r1 > r2 ? r1 - r2 : r2 - r1;

        if (x1 == x2 && y1 == y2 && r1 == r2)
            printf("-1\n");
        else if (distanse < r1 + r2 && subtract < distanse)
            printf("2\n");
        else if (distanse == r1 + r2 || distanse == subtract)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}