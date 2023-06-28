/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX
#define MOD (10e9 + 7)

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;
vector<int> tree;
vector<int> a;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int value, int oper)
{
    if (start == end)
    {
        if (oper == 1)
            tree[node] = (tree[node] + value) % MOD;
        else if (oper == 2)
            tree[node] = (tree[node] * value) % MOD;
        else if (oper == 3)
            tree[node] = value;

        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, value, oper);
    update(node * 2 + 1, mid + 1, end, index, value, oper);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int lsum = query(node * 2, start, mid, left, right);
    int rsum = query(node * 2 + 1, mid + 1, end, left, right);

    return lsum + rsum;
}

signed main()
{
    scanf("%lld", &N);
    a.resize(N);
    int h = (int)ceil(log2(N + 2));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size, 0);

    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    int M;
    scanf("%lld", &M);

    while (M--)
    {
        int oper, x, y, v;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            scanf("%lld %lld %lld", &x, &y, &v);
            update(1, 0, N - 1, )
        }
    }

    return 0;
}