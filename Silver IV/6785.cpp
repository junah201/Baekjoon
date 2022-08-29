#include <bits/stdc++.h>
using namespace std;

int T, M, Ax, Ay, ans = -1, EXIT = 0;

int five[20] = {0, 1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};

int grid[5][5] = {
    {0, 1, 1, 1, 0},
    {0, 2, 1, 2, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

// cmd == 1 : 새로, cmd == 2 : fill, cmd == 3 : empty
int get(int idx, int x, int y, int cmd)
{
    if (idx == 0)
    {
        if (cmd == 1 || cmd == 3)
        {
            if (x == Ax && y == Ay)
            {
                EXIT = 1;
                ans = 0;
            }
            return 0;
        }
        else
        {
            if (x == Ax && y == Ay)
            {
                EXIT = 1;
                ans = 1;
            }
            return 0;
        }
    }

    if (cmd == 1)
    {
        int tmp = five[idx];
        for (int ty = 0; ty < 5; ty++)
            for (int tx = 0; tx < 5; tx++)
            {
                if (grid[ty][tx] == 1)
                    get(idx - 1, x + tmp * tx, y + tmp * ty, 2);
                else if (grid[ty][tx] == 0)
                    get(idx - 1, x + tmp * tx, y + tmp * ty, 3);
                else if (grid[ty][tx] == 2)
                    get(idx - 1, x + tmp * tx, y + tmp * ty, 1);
            }
    }
    else if (cmd == 2)
    {
        int tmp = five[idx + 1];
        if (x <= Ax && Ax < x + tmp && y <= Ay && Ay < y + tmp)
        {
            ans = 1;
            EXIT = 1;
        }
    }
    else if (cmd == 3)
    {
        int tmp = five[idx + 1];
        if (x <= Ax && Ax < x + tmp && y <= Ay && Ay < y + tmp)
        {
            ans = 0;
            EXIT = 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &M, &Ax, &Ay);
        EXIT = 0;
        get(M, 0, 0, 1);
        if (ans == 0)
            printf("empty\n");
        else if (ans == 1)
            printf("crystal\n");
    }
}