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
    p[fin(a)] = fin(b);
}

int main()
{
    scanf("%d %d", &N, &M);
    p.resize(N + 1);
    for (int i = 0; i <= N; i++)
        p[i] = i;
    for (int i = 0, cmd, a, b; i < M; i++)
    {
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0)
        {
            uni(a, b);
        }
        else if (cmd == 1)
        {
            if (fin(a) == fin(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}