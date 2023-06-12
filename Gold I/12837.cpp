/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void update(vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || end < index)
        return;

    if (start == end)
    {
        tree[node] += val;
        return;
    }

    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, index, val);
    update(tree, node * 2 + 1, mid + 1, end, index, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int lsum = query(tree, node * 2, start, mid, left, right);
    int rsum = query(tree, node * 2 + 1, mid + 1, end, left, right);

    return lsum + rsum;
}

signed main()
{
    int N, Q;
    scanf("%lld %lld", &N, &Q);

    vector<int> a(N, 0);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << h + 1) + 1;
    vector<int> tree(tree_size, 0);

    while (Q--)
    {
        int oper, p, x;
        scanf("%lld %lld %lld", &oper, &p, &x);

        if (oper == 1)
        {
            update(tree, 1, 0, N - 1, p - 1, x);
        }
        else
        {
            printf("%lld\n", query(tree, 1, 0, N - 1, p - 1, x - 1));
        }
    }

    return 0;
}