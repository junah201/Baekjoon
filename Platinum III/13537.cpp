/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(v) v.begin(), v.end()
#define INF LONG_LONG_MAX

int N, Q;
vector<vector<int>> tree;
vector<int> a;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].emplace_back(a[start]);
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(all(tree[node * 2]), all(tree[node * 2 + 1]), tree[node].begin());
}

int query(int node, int start, int end, int left, int right, int target)
{
    if (start > right || end < left)
        return 0;

    if (left <= start && end <= right)
    {
        return tree[node].end() - upper_bound(all(tree[node]), target);
    }

    int mid = (start + end) / 2;
    int lsum = query(node * 2, start, mid, left, right, target);
    int rsum = query(node * 2 + 1, mid + 1, end, left, right, target);

    return lsum + rsum;
}

signed main()
{
    scanf("%lld", &N);
    int h = (int)ceil(log2(N + 1));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);
    a.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    init(1, 0, N - 1);

    scanf("%lld", &Q);
    while (Q--)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        int ans = query(1, 0, N - 1, a - 1, b - 1, c);
        printf("%lld\n", ans);
    }

    return 0;
}