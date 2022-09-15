#include <bits/stdc++.h>
using namespace std;

void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
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
void update(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int index, long long val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
long long query(vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    long long lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    long long rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<long long> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);
    M += K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    init(a, tree, 1, 0, N - 1);
    while (M--)
    {
        int what;
        scanf("%d", &what);
        if (what == 1)
        {
            int index;
            long long val;
            scanf("%d %lld", &index, &val);
            update(a, tree, 1, 0, N - 1, index - 1, val);
        }
        else if (what == 2)
        {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%lld\n", query(tree, 1, 0, N - 1, left - 1, right - 1));
        }
    }
    return 0;
}