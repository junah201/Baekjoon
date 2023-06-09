/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
int INF = LONG_LONG_MAX;

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int T;

void init(vector<int> &a, vector<pair<int, int>> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = {a[start], a[start]};
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = {
            min(tree[node * 2].first, tree[node * 2 + 1].first),
            max(tree[node * 2].second, tree[node * 2 + 1].second)};
    }
}

void update(vector<int> &a, vector<pair<int, int>> &tree, int node, int start, int end, int index)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        tree[node] = {a[index], a[index]};
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
    tree[node] = {
        min(tree[node * 2].first, tree[node * 2 + 1].first),
        max(tree[node * 2].second, tree[node * 2 + 1].second)};
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return {INF, -INF};
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    auto lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    auto rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return {
        min(lsum.first, rsum.first),
        max(lsum.second, rsum.second)};
}

void solve()
{
    int N, K;
    scanf("%lld %lld", &N, &K);
    vector<long long> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<pair<int, int>> tree(tree_size);

    for (int i = 0; i < N; i++)
        a[i] = i;

    init(a, tree, 1, 0, N - 1);

    while (K--)
    {
        int oper, p, q;
        scanf("%lld %lld %lld", &oper, &p, &q);

        if (oper == 0)
        {
            swap(a[p], a[q]);
            update(a, tree, 1, 0, N - 1, p);
            update(a, tree, 1, 0, N - 1, q);
        }
        else
        {
            auto [mn, mx] = query(tree, 1, 0, N - 1, min(p, q), max(p, q));
            if (mn == min(p, q) && mx == max(p, q))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

signed main()
{
    scanf("%lld", &T);
    while (T--)
        solve();
    return 0;
}