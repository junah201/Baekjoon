#include <bits/stdc++.h>
using namespace std;

int T, N;
int p[200002], si[200002];
map<string, int> mp;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    if (fin(a) == fin(b))
        return;
    si[fin(a)] += si[fin(b)];
    p[fin(b)] = p[fin(a)];
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        mp.clear();
        for (int i = 0, idx = 0; i < N; i++)
        {
            char a[21], b[21];
            scanf("%s %s", a, b);
            string A = a, B = b;
            // printf("%s %s\n", a, b);
            if (mp.find(A) == mp.end())
            {
                mp[A] = idx;
                p[idx] = idx;
                si[idx] = 1;
                idx++;
            }
            if (mp.find(B) == mp.end())
            {

                mp[B] = idx;
                p[idx] = idx;
                si[idx] = 1;
                idx++;
            }

            // printf("%d %d\n", mp[A], mp[B]);
            uni(mp[A], mp[B]);
            printf("%d\n", si[fin(mp[A])]);
        }
    }
}