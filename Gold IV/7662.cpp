/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int T;

void solve()
{
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int>>> g_pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> l_pq;

    scanf("%lld", &N);
    vector<int> visited(N, 0);

    for (int i = 0; i < N; i++)
    {
        char oper;
        int value;
        scanf(" %c %lld", &oper, &value);

        if (oper == 'I')
        {
            g_pq.emplace(value, i);
            l_pq.emplace(value, i);
            visited[i] = 1;
        }
        else if (oper == 'D')
        {
            if (value == -1)
            {
                // 이미 지운 값 삭제
                while (!l_pq.empty() && visited[l_pq.top().second] == 0)
                {
                    l_pq.pop();
                }
                if (!l_pq.empty())
                {
                    visited[l_pq.top().second] = 0;
                }
            }
            else if (value == 1)
            {
                // 이미 지운 값 삭제
                while (!g_pq.empty() && visited[g_pq.top().second] == 0)
                {
                    g_pq.pop();
                }
                if (!g_pq.empty())
                {
                    visited[g_pq.top().second] = 0;
                }
            }
        }
    }

    while (!l_pq.empty() && visited[l_pq.top().second] == 0)
    {
        l_pq.pop();
    }

    while (!g_pq.empty() && visited[g_pq.top().second] == 0)
    {
        g_pq.pop();
    }

    int sum = std::accumulate(visited.begin(), visited.end(), 0);

    if (sum)
        printf("%lld %lld\n", g_pq.top().first, l_pq.top().first);
    else
        printf("EMPTY\n");
}

signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}