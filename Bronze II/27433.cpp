/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;

long long get(int idx)
{
    if (idx == 0)
        return 1;
    return get(idx - 1) * idx;
}

int main()
{
    scanf("%d", &N);
    printf("%lld", get(N));

    return 0;
}