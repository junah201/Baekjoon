#include <bits/stdc++.h>
using namespace std;

int N, sum;

int main()
{
    while (true)
    {
        scanf("%d", &N);
        if (N == -1)
            break;
        sum += N;
    }
    printf("%d", sum);
    return 0;
}