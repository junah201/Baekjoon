// 2669 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/source/42729765

#include <bits/stdc++.h>
using namespace std;

int arr[101][101], ans;

int main()
{
    for (int i = 0, x1, y1, x2, y2; i < 4; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
                arr[y][x] = 1;
    }
    for (int y = 1; y <= 100; y++)
        for (int x = 1; x <= 100; x++)
            ans += arr[y][x];

    printf("%d", ans);
    return 0;
}