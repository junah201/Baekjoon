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
vector<int> inp;
vector<int> visited;
int a, b;

signed main()
{
    scanf("%lld", &N);
    inp.resize(N);
    visited.resize(N, INF);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &inp[i]);
    }
    scanf("%lld %lld", &a, &b);
    a--;
    b--;

    queue<pair<int, int>> q;
    q.emplace(a, 0);
    visited[a] = 0;

    while (!q.empty())
    {
        auto [idx, cnt] = q.front();
        q.pop();

        for (int i = inp[idx]; i + idx < N; i += inp[idx])
        {
            int nidx = i + idx;
            if (visited[nidx] <= cnt + 1)
                continue;
            visited[nidx] = cnt + 1;
            if (nidx == b)
            {
                printf("%lld", cnt + 1);
                return 0;
            }
            q.emplace(nidx, cnt + 1);
        }
        for (int i = -inp[idx]; i + idx >= 0; i -= inp[idx])
        {
            int nidx = i + idx;
            if (visited[nidx] <= cnt + 1)
                continue;
            visited[nidx] = cnt + 1;
            if (nidx == b)
            {
                printf("%lld", cnt + 1);
                return 0;
            }
            q.emplace(nidx, cnt + 1);
        }
    }

    printf("-1");

    return 0;
}