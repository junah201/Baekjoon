#include <bits/stdc++.h>
using namespace std;

int phone[20], N, Y, M;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &phone[i]);
    for (int i = 0; i < N; i++)
    {
        Y += ((phone[i] / 30) + 1) * 10;
        M += ((phone[i] / 60) + 1) * 15;
    }

    if (Y > M)
        printf("M");

    else if (Y < M)
        printf("Y");
    else
        printf("Y M");

    printf(" %d", min(Y, M));
    return 0;
}