// 5543 상근날드
// https://www.acmicpc.net/source/40089602

#include <bits/stdc++.h>
using namespace std;

int s, j, h, c, x;

int main()
{
    scanf("%d %d %d %d %d", &s, &j, &h, &c, &x);
    printf("%d", min(s, min(j, h)) + min(c, x) - 50);
    return 0;
}