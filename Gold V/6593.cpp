#include <bits/stdc++.h>
using namespace std;

int L, R, C;
char inp[32][32][32];

int main()
{
    scanf("%d %d %d", &L, &R, &C);
    for (int ray = 0; ray < L; ray++)
        for (int y = 0; y < R; y++)
            for (int x = 0; x < C; x++)
                scanf("%c", &inp[ray][y][x]);
}