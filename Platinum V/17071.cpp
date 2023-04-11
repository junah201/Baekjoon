/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int N, K;
int visited[500002][2];

int oper(int value, int idx)
{
    if (idx == 0)
        return value + 1;
    if (idx == 1)
        return value - 1;
    if (idx == 2)
        return value * 2;
    return value * 2;
}

int solve()
{
    scanf("%d %d", &N, &K);
    vector<vector<int>> visited(500002, vector<int>(2, -1));

    queue<pair<int, int>> q;
    q.emplace(N, 0);
    visited[N][0] = 0;

    while (!q.empty())
    {
        auto [n, idx] = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int next_n = oper(n, i);

            if (next_n <= 500000 && next_n >= 0 && visited[next_n][(idx + 1) % 2] == -1)
            {
                visited[next_n][(idx + 1) % 2] = idx + 1;
                q.emplace(next_n, idx + 1);
            }
        }
    }

    int tmp = K;
    for (int i = 0; i <= 1000; i++)
    {
        tmp += i;
        if (tmp > 500000)
            break;
        if ((visited[tmp][i % 2] != -1) && (visited[tmp][i % 2] <= i))
            return i;
    }

    return -1;
}

int main()
{

    printf("%d", solve());
    return 0;
}