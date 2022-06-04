#include <bits/stdc++.h>
using namespace std;

int max_ans, min_ans;
int N, M;

int p[1002];

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
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++)
        p[i] = i;
    for (int i = 0, start, end, dis; i <= M; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        v.push_back({!dis, {start, end}});
    }

    sort(v.begin(), v.end());

    for (auto [dis, tmp] : v)
    {
        auto [start, end] = tmp;
        if (fin(start) != fin(end))
        {
            min_ans += dis;
            uni(start, end);
        }
    }

    for (int i = 0; i <= N; i++)
        p[i] = i;
    sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());

    for (auto [dis, tmp] : v)
    {
        auto [start, end] = tmp;
        if (fin(start) != fin(end))
        {
            max_ans += dis;
            uni(start, end);
        }
    }

    printf("%d", max_ans * max_ans - min_ans * min_ans);
    return 0;
}