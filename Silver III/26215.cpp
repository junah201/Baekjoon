#include <bits/stdc++.h>
using namespace std;

int N, ans;
priority_queue<int> inp;

int main()
{
    scanf("%d", &N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        inp.emplace(tmp);
    }
    while (!inp.empty())
    {
        int top1 = inp.top();
        inp.pop();

        if (!inp.empty())
        {
            int top2 = inp.top();
            inp.pop();
            if (top2 - 1)
                inp.emplace(top2 - 1);
        }
        if (top1 - 1)
            inp.emplace(top1 - 1);
        ans++;
    }
    if (ans > 1440)
        printf("-1");
    else
        printf("%d", ans);
}