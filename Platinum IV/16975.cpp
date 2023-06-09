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
        tree[node] =
            tree[node * 2] + tree[node * 2 + 1];
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
        tree[node] += val;
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] =
        tree[node * 2] + tree[node * 2 + 1];
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
    auto lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    auto rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return lsum + rsum;
}

signed main()
{
    int N, Q;
    scanf("%lld", &N);
    vector<long long> a(N + 1);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size);

    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i < N; i++)
    {
        dprintf("%lld : %lld\n", i + 1, query(tree, 1, 0, N - 1, 0, i));
    }
    scanf("%lld", &Q);
    while (Q--)
    {
        int oper;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            int i, j, k;
            scanf("%lld %lld %lld", &i, &j, &k);
            dprintf("== %lld %lld %lld ==\n", i, j, k);
            update(a, tree, 1, 0, N - 1, i - 1, k);
            update(a, tree, 1, 0, N - 1, j, -k);
            for (int i = 0; i < N; i++)
            {
                dprintf("%lld : %lld\n", i + 1, query(tree, 1, 0, N - 1, 0, i));
            }
        }
        else
        {
            int x;
            scanf("%lld", &x);
            int result1 = query(tree, 1, 0, N - 1, 0, x - 1);
            printf("%lld\n", a[x - 1] + result1);
        }
    }

    return 0;
}