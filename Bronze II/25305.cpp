/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, K, inp[1002];

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + N);

    printf("%d", inp[N - K]);

    return 0;
}