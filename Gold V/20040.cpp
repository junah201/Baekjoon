/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p;

int fin(int x)
{
    if (p[x] == x)
        return x;

    return p[x] = fin(p[x]);
}

void marge(int a, int b)
{
    a = fin(a);
    b = fin(b);

    p[a] = b;
}

int main()
{
    scanf("%d %d", &N, &M);
    p.resize(N + 2);

    for (int i = 0; i <= N; i++)
        p[i] = i;

    for (int i = 1, a, b; i <= M; i++)
    {
        scanf("%d %d", &a, &b);
        a = fin(a);
        b = fin(b);

        if (a == b)
        {
            printf("%d", i);
            return 0;
        }

        marge(a, b);
    }

    printf("0");
    return 0;
}