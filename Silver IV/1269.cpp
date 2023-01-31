/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int A, B;
set<int> set_A, set_B, set_total, ans;

int main()
{
    scanf("%d %d", &A, &B);
    for (int i = 0, tmp; i < A; i++)
    {
        scanf("%d", &tmp);
        set_A.insert(tmp);
    }
    for (int i = 0, tmp; i < B; i++)
    {
        scanf("%d", &tmp);
        set_B.insert(tmp);
        if (set_A.find(tmp) != set_A.end())
        {
            set_total.insert(tmp);
        }
    }

    for (auto i = set_A.begin(); i != set_A.end(); i++)
    {
        if (set_total.find(*i) == set_total.end())
            ans.insert(*i);
    }
    for (auto i = set_B.begin(); i != set_B.end(); i++)
    {
        if (set_total.find(*i) == set_total.end())
            ans.insert(*i);
    }

    printf("%d", ans.size());

    return 0;
}