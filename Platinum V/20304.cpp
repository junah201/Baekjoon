/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> V;
int preset[20];

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0, tmp; i < M; i++)
    {
        scanf("%d", &tmp);
        V.emplace_back(tmp);
    }

    queue<int> q;
    vector<int> visited(N + 2, INT_MIN);

    for (auto used_pass : V)
    {
        q.emplace(used_pass);
        visited[used_pass] = 0;
    }

    for (int i = 0; i < 20; i++)
    {
        preset[i] = (1 << i);
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 20; i++)
        {
            int new_pass = now ^ preset[i];

            if (new_pass > N)
                continue;

            if (visited[new_pass] != INT_MIN)
                continue;

            ans = max(ans, visited[now] + 1);

            visited[new_pass] = visited[now] + 1;

            q.emplace(new_pass);
        }
    }

    printf("%d", ans);

    return 0;
}