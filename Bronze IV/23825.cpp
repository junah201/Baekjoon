// 23825 SASA 모형을 만들어보자
// https://www.acmicpc.net/source/40039263

#include <bits/stdc++.h>
using namespace std;

int N, M, ans;

int main()
{
    scanf("%d %d", &N, &M);
    printf("%d", min(N, M) / 2);
    return 0;
}