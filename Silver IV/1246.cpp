#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int ans1 = -1, ans2;

int main()
{
    scanf("%d %d", &N, &M);
    while (M--)
    {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (ans1 < min(N, (int)v.size() - i) * v[i])
        {
            ans1 = min(N, (int)v.size() - i) * v[i];
            ans2 = v[i];
        }
    }
    printf("%d %d", ans2, ans1);
    return 0;
}