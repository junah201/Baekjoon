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
        tree[node] = {a[start], start};
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
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
        tree[node] = {val, start};
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return {INF, INF};
    if (left <= start && end <= right)
        return tree[node];

    return min(query(tree, node * 2, start, (start + end) / 2, left, right), query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
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
            int idx, val;
            scanf("%lld %lld", &idx, &val);
            update(a, tree, 1, 0, N - 1, idx - 1, val);
        }
        else if (oper == 2)
        {
            int s, e;
            scanf("%lld %lld", &s, &e);
            auto [min_value, min_idx] = query(tree, 1, 0, N - 1, s - 1, e - 1);
            printf("%lld\n", min_idx + 1);
        }
    }

    return 0;
}