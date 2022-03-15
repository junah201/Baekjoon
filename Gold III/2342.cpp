#include <bits/stdc++.h>
using namespace std;

int cmd, cost;
int rx[5] = {-1, 1, 0, 1, 2};
int ry[5] = {-1, 2, 1, 0, 1};

struct xy
{
    int x, y;
};

struct xy DDR[5] = {{-1, -1}, {1, 2}, {0, 1}, {1, 0}, {2, 1}};
struct xy r = {1, 1};
struct xy l = {1, 1};

int main()
{
    while (scanf("%d", &cmd) && cmd != 0)
    {
        int tr = abs(r.x - DDR[cmd].x) + abs(r.y - DDR[cmd].y);
        int tl = abs(l.x - DDR[cmd].x) + abs(l.y - DDR[cmd].y);
        if (tr < tl)
        {
            if (tr == 0)
                cost += 1;
            else if (r.x == 1 && r.y == 2)
            {
                if (tr == 1)
                    cost += 2;
                else if ()
            }
            else
            {
                        }
        }

        if (!min(tr, tl))
            cost += 1;
        else
            cost += 3 * min(tr, tl);
        if (tr < tl)
            r = DDR[cmd];
        else
            l = DDR[cmd];
        printf("(%d, %d) : (%d, %d) - %d\n", r.x, r.y, l.x, l.y, cost);
    }
    printf("%d", cost);
    return 0;
}