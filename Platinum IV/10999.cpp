/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N;

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(a, tree, node * 2, start, mid);
        init(a, tree, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int diff)
{
    update_lazy(tree, lazy, node, start, end);

    if (right < start || left > end)
        return;

    if (left <= start && end <= right)
    {
        tree[node] += (end - start + 1) * diff;
        if (start != end)
        {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(tree, lazy, node * 2, start, mid, left, right, diff);
    update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right)
{
    update_lazy(tree, lazy, node, start, end);

    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int lsum = query(tree, lazy, node * 2, start, mid, left, right);
    int rsum = query(tree, lazy, node * 2 + 1, mid + 1, end, left, right);

    return lsum + rsum;
}

signed main()
{
    int N, K, M;
    scanf("%lld %lld %lld", &N, &M, &K);
    vector<int> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size), lazy(tree_size, 0);
    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    init(a, tree, 1, 0, N - 1);

    M += K;
    while (M--)
    {
        int oper, start, end, val;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            scanf("%lld %lld %lld", &start, &end, &val);
            update_range(tree, lazy, 1, 0, N - 1, start - 1, end - 1, val);
        }
        else if (oper == 2)
        {
            scanf("%lld %lld", &start, &end);
            printf("%lld\n", query(tree, lazy, 1, 0, N - 1, start - 1, end - 1));
        }
    }

    return 0;
}