/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;

void get(vector<int> &T, int x, int deepth)
{
    if (deepth == 1)
    {
        T[x] = 1;
        return;
    }
    get(T, x, deepth / 3);
    get(T, x + 2 * deepth / 3, deepth / 3);
}

void solve(int N)
{
    int K = 1;
    for (int i = 0; i < N; i++)
    {
        K *= 3;
    }
    vector<int> T(K, 0);
    get(T, 0, K);

    for (int i = 0; i < K; i++)
    {
        if (T[i])
        {
            printf("-");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}

signed main()
{
    int n;
    while (scanf("%lld", &n) != EOF)
    {
        solve(n);
    }

    return 0;
}