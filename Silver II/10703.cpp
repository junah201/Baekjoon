#include <bits/stdc++.h>
using namespace std;

int X, Y;
char picture[3002][3002];
char new_picture[3002][3002];
int land[3002];
int star[3002];

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf(" %c", &picture[y][x]);

    int min_dis = INT_MAX;

    for (int x = 0; x < X; x++)
    {
        land[x] = Y - 1;
        star[x] = INT_MAX;
        for (int y = Y - 1; y >= 0; y--)
        {
            if (picture[y][x] == '#')
                land[x] = y;

            if (picture[y][x] == 'X')
            {
                star[x] = y;
                break;
            }
        }
    }

    for (int x = 0; x < X; x++)
    {
        if (star[x] == INT_MAX)
            continue;
        min_dis = min(min_dis, land[x] - star[x]);
    }

    for (int x = 0; x < X; x++)
        for (int y = Y - 1; y >= 0; y--)
        {
            if (picture[y][x] == '#')
                new_picture[y][x] = '#';
            else if (new_picture[y][x] != 'X')
                new_picture[y][x] = '.';

            if (picture[y][x] == 'X')
                new_picture[y + min_dis - 1][x] = 'X';
        }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
            printf("%c", new_picture[y][x]);
        printf("\n");
    }
}
