/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
<<<<<<< HEAD
#define all(v) v.begin(), v.end()
#define INF LONG_LONG_MAX

int N, Q;
vector<vector<int>> tree;
vector<int> a;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].emplace_back(a[start]);
=======
#define INF LONG_LONG_MAX
#define SIZE 1000000

int N, K;
vector<int> tree, a(SIZE + 2, 0);

void update(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
        return;

    if (start == end)
    {
        tree[node] += value;
        a[index] += value;
>>>>>>> 94875d1375dd7575b207eaeb7633c72fc6b0d3f9
        return;
    }

    int mid = (start + end) / 2;
<<<<<<< HEAD
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(all(tree[node * 2]), all(tree[node * 2 + 1]), tree[node].begin());
}

int query(int node, int start, int end, int left, int right, int target)
{
    vector<int> result;
    if (end < left || start > right)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return lower_bound(all(tree[node]), target) - tree[node].begin();
    }

    int mid = (start + end) / 2;
    int lsum = query(node * 2, start, mid, left, right, target);
    int rsum = query(node * 2 + 1, mid + 1, end, left, right, target);
=======
    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int lsum = query(node * 2, start, mid, left, right);
    int rsum = query(node * 2 + 1, mid + 1, end, left, right);
>>>>>>> 94875d1375dd7575b207eaeb7633c72fc6b0d3f9

    return lsum + rsum;
}

<<<<<<< HEAD
int get(int start, int end, int target)
{
    int low = -1e9;
    int high = 1e9;
    int mid, ans = -1e9;

    while (low <= high)
    {
        mid = (low + high) / 2;
        int q = query(1, 0, N - 1, start - 1, end - 1, mid);
        if (q < target)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
=======
int get_cnt(int idx)
{
    return query(1, 0, SIZE, 0, idx);
}

int get_nth(int ideal_mid_cnt)
{
    int low = 0, high = SIZE, mid, result;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int mid_value = get_cnt(mid);

        if (mid_value >= ideal_mid_cnt && a[mid])
            result = mid;

        if (mid_value > ideal_mid_cnt)
            high = mid - 1;
        else if (mid_value < ideal_mid_cnt)
            low = mid + 1;
        else
        {
            high = mid - 1;

            if (mid_value != get_cnt(mid - 1))
            {
                return mid;
            }
        }
    }
    return result;
>>>>>>> 94875d1375dd7575b207eaeb7633c72fc6b0d3f9
}

signed main()
{
<<<<<<< HEAD
    scanf("%lld %lld", &N, &Q);
    int h = (int)ceil(log2(N + 1));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    init(1, 0, N - 1);

    while (Q--)
    {
        int i, j, k;
        scanf("%lld %lld %lld", &i, &j, &k);

        printf("%lld\n", get(i, j, k));
    }

    return 0;
}
=======
    scanf("%lld", &N);
    int h = (int)ceil(log2(SIZE + 2));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size, 0);

    for (int i = 0; i < N; i++)
    {
        int oper, b, c;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            scanf("%lld", &b);
            int result = get_nth(b);
            printf("%lld\n", result);
            update(1, 0, SIZE, result, -1);
        }
        else if (oper == 2)
        {
            scanf("%lld %lld", &b, &c);
            update(1, 0, SIZE, b, c);
        }
    }

    return 0;
}
>>>>>>> 94875d1375dd7575b207eaeb7633c72fc6b0d3f9
