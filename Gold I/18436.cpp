/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

int MOD = 1000000007;
int INF = LONG_LONG_MAX;

void init(vector<int> &a, vector<pair<int, int>> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = {
            (int)(a[start] % 2 == 0),
            (int)(a[start] % 2 == 1)};
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = {
            tree[node * 2].first + tree[node * 2 + 1].first,
            tree[node * 2].second + tree[node * 2 + 1].second};
    }
}

void update(vector<int> &a, vector<pair<int, int>> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        a[index] = val;
        tree[node] = {
            (int)(val % 2 == 0),
            (int)(val % 2 == 1)};
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = {
        tree[node * 2].first + tree[node * 2 + 1].first,
        tree[node * 2].second + tree[node * 2 + 1].second};
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return {0, 0};
    if (left <= start && end <= right)
        return tree[node];

    pair<int, int> lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    pair<int, int> rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return {
        lsum.first + rsum.first,
        lsum.second + rsum.second};
}

signed main()
{
    int N, M;
    scanf("%lld", &N);
    vector<int> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<pair<int, int>> tree(tree_size, {INF, -INF});

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    init(a, tree, 1, 0, N - 1);

    scanf("%lld", &M);

    while (M--)
    {
        int oper;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            int index, val;
            scanf("%lld %lld", &index, &val);
            update(a, tree, 1, 0, N - 1, index - 1, val);
        }
        else if (oper == 2)
        {
            int s, e;
            scanf("%lld %lld", &s, &e);
            auto [zero, one] = query(tree, 1, 0, N - 1, s - 1, e - 1);
            printf("%lld\n", zero);
        }
        else if (oper == 3)
        {
            int s, e;
            scanf("%lld %lld", &s, &e);
            auto [zero, one] = query(tree, 1, 0, N - 1, s - 1, e - 1);
            printf("%lld\n", one);
        }
    }

    return 0;
}