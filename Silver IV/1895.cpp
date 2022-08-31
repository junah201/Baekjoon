#include <bits/stdc++.h>
using namespace std;

int X, Y, T, ans;
int inp[42][42];

int 중앙값구하기(int x, int y)
{
    vector<int> v;

    for (int tx = x; tx < x + 3; tx++)
        for (int ty = y; ty < y + 3; ty++)
            v.push_back(inp[ty][tx]);

    sort(v.begin(), v.end());
    return v[4];
}

int main()
{
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            scanf("%d", &inp[y][x]);
    scanf("%d", &T);
    for (int y = 0; y < Y - 2; y++)
        for (int x = 0; x < X - 2; x++)
        {
            if (중앙값구하기(x, y) >= T)
                ans++;
        }
    printf("%d", ans);
    return 0;
}