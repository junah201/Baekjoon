/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;
int mp[1000002];
vector<int> v;
stack<int> s, ans;

int main()
{
    scanf("%d", &N);

    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);

        mp[tmp]++;
        v.push_back(tmp);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        ans.push(-1);
        while (!s.empty())
        {
            if (mp[v[i]] < mp[s.top()])
            {
                ans.pop();
                ans.push(s.top());
                break;
            }
            s.pop();
        }
        s.push(v[i]);
    }

    while (!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }

    return 0;
}