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

void init(vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = 0;
    }
    else
    {
        init(tree, node * 2, start, (start + end) / 2);
        init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] =
            tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(vector<int> &tree, int node, int start, int end, int index)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        tree[node] += 1;
        return;
    }
    update(tree, node * 2, start, (start + end) / 2, index);
    update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
    tree[node] =
        tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int> &tree, int node, int nth, int left, int right)
{
    if (left == right)
    {
        tree[node] -= 1;
        return left;
    }

    int mid = (left + right) / 2;

    int res = 0;
    if (nth <= tree[node * 2])
        res = query(tree, node * 2, nth, left, mid);
    else
        res = query(tree, node * 2 + 1, nth - tree[node * 2], mid + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

    return res;
}

signed main()
{
    int N, K;
    int MAX = 100002;
    scanf("%lld %lld", &N, &K);
    int h = (int)ceil(log2(MAX));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size);

    for (int i = 1; i <= N; i++)
        update(tree, 1, 0, MAX - 1, i);

    int tmp = K;

    printf("<");
    while (N)
    {
        while (tmp > N)
            tmp -= N;
        printf("%lld", query(tree, 1, tmp, 0, MAX - 1));
        tmp += K - 1;
        N--;
        if (N != 0)
            printf(", ");
    }
    printf(">");

    return 0;
}
