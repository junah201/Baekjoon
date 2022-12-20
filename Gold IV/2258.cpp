#include <bits/stdc++.h>
using namespace std;

int N, M, ans = -1;
vector<pair<int, int>> meat;
int total_w, last_c, total_c;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, w, c; i < N; i++)
    {
        scanf("%d %d", &w, &c);
        meat.emplace_back(c, w);
    }
    sort(meat.begin(), meat.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        auto [c1, w1] = a;
        auto[c2, w2] = b;
            if(c1 == c2) return w1 > w2;
            return c1 < c2; });

    for (auto [c, w] : meat)
    {
        if (last_c != c)
            total_c = 0;
        total_c += c;
        last_c = c;
        total_w += w;

        if (total_w >= M)
        {
            if (ans == -1)
                ans = total_c;
            ans = min(ans, total_c);
        }
    }
    printf("%d", ans);
}