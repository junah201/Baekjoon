/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    init(a, tree, node * 2, start, mid);
    init(a, tree, node * 2 + 1, mid + 1, end);

    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || end < index)
    {
        return;
    }
    if (start == end)
    {
        a[start] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(a, tree, node * 2, start, mid, index, val);
    update(a, tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
    {
        return 1;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lsum = query(tree, node * 2, start, mid, left, right);
    int rsum = query(tree, node * 2 + 1, mid + 1, end, left, right);

    return lsum * rsum;
}

void solve(int N, int K)
{
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> a(N);
    vector<int> tree(tree_size + 1, 1);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > 0)
            a[i] = 1;
        else if (a[i] < 0)
            a[i] = -1;
    }

    init(a, tree, 1, 0, N - 1);

    while (K--)
    {
        char oper;
        int i, j;
        scanf(" %c %lld %lld", &oper, &i, &j);

        if (oper == 'C')
        {
            if (j > 0)
                j = 1;
            else if (j < 0)
                j = -1;
            update(a, tree, 1, 0, N - 1, i - 1, j);
        }
        else if (oper == 'P')
        {
            int result = query(tree, 1, 0, N - 1, i - 1, j - 1);
            if (result == 1)
                printf("+");
            else if (result == 0)
                printf("0");
            else if (result < 0)
                printf("-");
        }
    }
    printf("\n");
    return;
}

signed main()
{
    int N, K;
    while (scanf("%lld %lld", &N, &K) != EOF)
        solve(N, K);

    return 0;
}