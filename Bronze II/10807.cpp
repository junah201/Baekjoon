#include <bits/stdc++.h>
using namespace std;

int N, V[300];

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        V[tmp + 100]++;
    }
    scanf("%d", &N);

    printf("%d", V[N + 100]);
    return 0;
}