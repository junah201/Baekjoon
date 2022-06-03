#include <bits/stdc++.h>
using namespace std;

int N, ans;
int W[100002];
int P[100002][100002];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &W[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &P[i][j]);
}