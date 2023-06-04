/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        a[index] += val;
        tree[node] += val;
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    int rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

void solve()
{
    int N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);
    vector<int> a(N, 0);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size, 0);

    M += K;
    init(a, tree, 1, 0, N - 1);

    while (M--)
    {
        char oper;
        scanf(" %c", &oper);
        if (oper == 'Q')
        {
            int left, right;
            scanf("%lld %lld", &left, &right);
            printf("%lld\n", query(tree, 1, 0, N - 1, min(left, right) - 1, max(left, right) - 1));
        }
        else if (oper == 'P')
        {
            int index, val;
            scanf("%lld %lld", &index, &val);
            update(a, tree, 1, 0, N - 1, index - 1, val);
        }
    }
}

signed main()
{
    int T;
    scanf("%lld", &T);
    while (T--)
        solve();

    return 0;
}