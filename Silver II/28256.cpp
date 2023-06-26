/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
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

int T;

int solve()
{
    char inp[3][3];

    bool is_x = false;

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            scanf(" %1c", &inp[y][x]);
            if (inp[y][x] == 'X')
                is_x = true;
        }
    }

    int N;
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    if (!is_x)
    {
        if (N == 1 && A[0] == 8)
            return 1;
        return 0;
    }

    queue<char> q;
    q.emplace(inp[0][0]);
    q.emplace(inp[0][1]);
    q.emplace(inp[0][2]);
    q.emplace(inp[1][2]);
    q.emplace(inp[2][2]);
    q.emplace(inp[2][1]);
    q.emplace(inp[2][0]);
    q.emplace(inp[1][0]);

    while (!q.empty())
    {
        if (q.front() == 'X')
        {
            q.pop();
            break;
        }
        q.emplace(q.front());
        q.pop();
    }

    vector<int> ans;

    int cnt = 0;

    while (!q.empty())
    {
        if (q.front() == 'O')
        {
            cnt++;
            q.pop();
        }
        else
        {
            if (cnt != 0)
                ans.emplace_back(cnt);
            cnt = 0;
            q.pop();
        }
    }

    if (cnt)
        ans.emplace_back(cnt);

    sort(ans.begin(), ans.end());

    if (ans.size() != A.size())
    {
        return 0;
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        if (ans[i] != A[i])
            return 0;
    }

    return 1;
}

signed main()
{
    scanf("%lld", &T);

    while (T--)
    {
        printf("%lld\n", solve());
    }
    return 0;
}