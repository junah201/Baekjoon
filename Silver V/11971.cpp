/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M, ans;
vector<int> limit;
vector<int> user;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0, dis, speed; i < N; i++)
    {
        scanf("%d %d", &dis, &speed);
        while (dis--)
        {
            limit.emplace_back(speed);
        }
    }

    for (int i = 0, dis, speed; i < M; i++)
    {
        scanf("%d %d", &dis, &speed);
        while (dis--)
        {
            user.emplace_back(speed);
        }
    }

    for (int i = 0; i < 100; i++)
    {
        ans = max(ans, user[i] - limit[i]);
    }

    printf("%d", ans);

    return 0;
}