// 1074  Z
// https://www.acmicpc.net/source/39525123

#include <stdio.h>

int car_idx, check;
int N, R, C;
int two[20] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

void get(int x, int y, int stack)
{
    if (check == 1)
        return;
    if (stack == 0)
    {
        if (x == C && y == R)
        {
            printf("%d", car_idx);
            check = 1;
        }
        car_idx++;
        return;
    }
    if (R < y + two[stack + 1] && R >= y && C < x + two[stack + 1] && C >= x)
    {
        get(x, y, stack - 1);
        get(x + two[stack], y, stack - 1);
        get(x, y + two[stack], stack - 1);
        get(x + two[stack], y + two[stack], stack - 1);
    }
    else
    {
        car_idx += two[stack + 1] * two[stack + 1];
    }
}

int main()
{
    scanf("%d %d %d", &N, &R, &C);
    get(0, 0, N);
    return 0;
}