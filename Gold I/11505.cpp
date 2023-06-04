/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

int MOD = 1000000007;

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start] % MOD;
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
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
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 1;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    long long lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    long long rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return (lsum * rsum) % MOD;
}

signed main()
{
    int N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);
    vector<long long> a(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size, 1);
    M += K;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    init(a, tree, 1, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%lld ", tree[i]);
    printf("\n");

    while (M--)
    {
        int what;
        scanf("%lld", &what);
        if (what == 1)
        {
            int index;
            long long val;
            scanf("%lld %lld", &index, &val);
            update(a, tree, 1, 0, N - 1, index - 1, val);
        }
        else if (what == 2)
        {
            int left, right;
            scanf("%lld %lld", &left, &right);
            printf("%lld\n", query(tree, 1, 0, N - 1, left - 1, right - 1));
        }
        printf("\n");
    }

    return 0;
}