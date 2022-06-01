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

void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);
    if (a != b)
        p[a] = b;
}

int main()
{
    scanf("%d %d", &N, &M);
    p.resize(N + 1);
    for (int i = 1; i <= N; i++)
        p[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1, x; j <= N; j++)
        {
            scanf("%d", &x);
            if (x)
                uni(i, j);
        }

    int tmp1, tmp2;
    scanf("%d", &tmp1);
    for (int i = 2; i <= M; i++)
    {
        scanf("%d", &tmp2);
        if (fin(tmp1) != fin(tmp2))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}