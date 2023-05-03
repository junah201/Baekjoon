/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;

struct A
{
    int value;
    int idx;
};

struct cmp
{
    bool operator()(A &a, A &b)
    {
        return a.value > b.value;
    }
};

int N, M, tmp;
priority_queue<A, vector<A>, cmp> pq;

signed main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        pq.push({tmp, i});

        if (pq.size() >= M)
        {
            while (!pq.empty())
            {
                if (pq.top().idx + M <= i)
                    pq.pop();
                else
                    break;
            }
        }

        printf("%d ", pq.top().value);
    }

    return 0;
}