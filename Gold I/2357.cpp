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
        tree[node] = {a[start], a[start]};
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = {
            min(tree[node * 2].first, tree[node * 2 + 1].first),
            max(tree[node * 2].second, tree[node * 2 + 1].second),
        };
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
        tree[node] = {val, val};
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = {
        min(tree[node * 2].first, tree[node * 2 + 1].first),
        max(tree[node * 2].second, tree[node * 2 + 1].second),
    };
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return {INF, -INF};
    if (left <= start && end <= right)
        return tree[node];

    pair<int, int> lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    pair<int, int> rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return {
        min(lsum.first, rsum.first),
        max(lsum.second, rsum.second),
    };
}

signed main()
{
    int N, M;
    scanf("%lld %lld", &N, &M);
    vector<int> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<pair<int, int>> tree(tree_size, {INF, -INF});

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    init(a, tree, 1, 0, N - 1);

    while (M--)
    {
        int s, e;
        scanf("%lld %lld", &s, &e);
        auto [mn, mx] = query(tree, 1, 0, N - 1, s - 1, e - 1);
        printf("%lld %lld\n", mn, mx);
    }

    return 0;
}