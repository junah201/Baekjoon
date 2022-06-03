#include <bits/stdc++.h>
using namespace std;

int N, ans;
char info[52][52];
int p[52];
vector<pair<int, pair<int, int>>> v;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);

    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &info[i][j]);
            if (info[i][j] == '0')
                continue;
            else if (info[i][j] >= 'a' && info[i][j] <= 'z')
            {
                v.push_back({info[i][j] - 'a' + 1, {i, j}});
                ans += info[i][j] - 'a' + 1;
            }
            else
            {
                v.push_back({info[i][j] - 'A' + 27, {i, j}});
                ans += info[i][j] - 'A' + 27;
            }
        }
    }

    sort(v.begin(), v.end());

    for (auto [dis, tmp] : v)
    {
        auto [start, end] = tmp;
        if (fin(start) != fin(end))
        {
            ans -= dis;
            uni(start, end);
        }
    }
    for (int i = 1; i < N; i++)
        if (fin(0) != fin(i))
        {
            printf("-1");
            return 0;
        }

    printf("%d", ans);
    return 0;
}