// 17388 와글바글 숭고한
// https://www.acmicpc.net/source/40537773

#include <bits/stdc++.h>
using namespace std;

int S, K, H;

int main()
{
    scanf("%d %d %d", &S, &K, &H);
    if (S + K + H >= 100)
        printf("OK");
    else
    {
        if (S == min(S, min(K, H)))
            printf("Soongsil");
        else if (K == min(S, min(K, H)))
            printf("Korea");
        else if (H == min(S, min(K, H)))
            printf("Hanyang");
    }
    return 0;
}