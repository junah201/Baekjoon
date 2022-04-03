#include <bits/stdc++.h>
using namespace std;

int N, cnt, del;
priority_queue<int> pq;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        pq.emplace(tmp);
    }
    while (!pq.empty())
    {
        del++;

        int cur = pq.top();
        pq.pop();

        printf("%d : %d\n", cur, del);

        if (cur - del <= 0)
            continue;
        else
            cnt += cur - del, del += cur - del;
    }
    printf("%d", cnt);
}