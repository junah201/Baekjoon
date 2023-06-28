/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N, M;
vector<int> a;
vector<pair<int, int>> tree;

int indexs_to_value(pair<int, int> &v)
{
    int result = 0;
    if (v.first != -1)
        result += a[v.first];
    if (v.second != -1)
        result += a[v.second];
    return result;
}

pair<int, int> new_max(pair<int, int> &p1, pair<int, int> &p2)
{
    pair<int, int> new_data, result = {-1, -1};
    new_data = {p1.first, p1.second};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;
    new_data = {p2.first, p2.second};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;
    new_data = {p1.first, p2.first};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;
    new_data = {p1.first, p2.second};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;
    new_data = {p1.second, p2.first};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;
    new_data = {p1.second, p2.second};
    if (indexs_to_value(result) < indexs_to_value(new_data))
        result = new_data;

    return result;
}

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = {start, -1};
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    tree[node] = new_max(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int index)
{
    if (start > index || end < index - 1)
        return;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);

    tree[node] = new_max(tree[node * 2], tree[node * 2 + 1]);
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return {-1, -1};

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> lsum = query(node * 2, start, mid, left, right);
    pair<int, int> rsum = query(node * 2 + 1, mid + 1, end, left, right);

    return new_max(lsum, rsum);
}

signed main()
{
    scanf("%lld", &N);

    int h = (int)ceil(log2(N + 2));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size, {-1, -1});

    a.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    init(1, 0, N - 1);

    scanf("%lld", &M);
    while (M--)
    {
        int oper, i, v;
        scanf("%lld %lld %lld", &oper, &i, &v);

        if (oper == 1)
        {
            a[i - 1] = v;
            update(1, 0, N - 2, i - 1);
        }
        else
        {
            auto res = query(1, 0, N - 1, i - 1, v - 1);
            printf("%lld\n", indexs_to_value(res));
        }
    }

    return 0;
}
