#include <stdio.h>

using namespace std;

int N, M;
int R, C, D;
int map[52][52];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 1};

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &R, &C, &D);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%d", &map[y][x]);
    while (true)
    {
        // 1번 쿼리
        if (map[C][R] == 0)
            map[C][R] = 2;
        // 2 쿼리 - a
        D = (D + 1) % 4;
        int rx = R + dx[D];
        int ry = C + dy[D];
        if (map[ry][rx] == 0)
        {
            R = rx;
            C = ry;
        }
        else
            continue;
    }
}