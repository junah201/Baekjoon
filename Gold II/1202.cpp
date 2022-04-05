#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
vector<pair<int, int>> jul;
vector<int> bag;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0, a, b; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        jul.emplace_back(a, b);
    }
    for (int i = 0, a; i < K; i++)
    {
        scanf("%d %d", &a);
        bag.emplace_back(a);
    }
    sort(bag.begin(), bag.end());
    for (auto i : bag)
    {
        int idx, tmp;
        for (int k = 0; k<jul.size();k++)
        {
            auto [W, V] = jul[k];
            if (W <= i) {
                if(tmp <V) {
                    tmp = V;
                    idx = k;
                }
            }
            else
                break;
        }
        ans += tmp;
        jul[idx] = {-1,-1};
    }
    printf("%d", ans);
    return 0;
}
