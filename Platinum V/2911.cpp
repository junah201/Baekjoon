#include <bits/stdc++.h>
using namespace std;

int N, M;
long long ans;
vector<pair<int, int>> v;
stack<int> s;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, pos, cnt; i < N; i++)
    {
        scanf("%d %d", &pos, &cnt);
        v.push_back({pos, cnt});
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        int cnt = i.second;
        if (s.empty() || s.top() < cnt)
            s.push(cnt);
        else if (s.top() != cnt)
        {
            ans += s.top() - cnt;
            s.pop();
            while (!s.empty() && s.top() > cnt)
                s.pop();
            if (s.empty() || s.top() != cnt)
                s.push(cnt);
        }
    }
    if (!s.empty())
        ans += s.top();
    printf("%lld", ans);
    return 0;
}
