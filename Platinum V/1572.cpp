/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N, K;
vector<int> tree, a(65536 + 2, 0);

void update(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
        return;

    if (start == end)
    {
        tree[node] += value;
        a[index] += value;
        return;
    }

    int mid = (start + end) / 2;
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

    return lsum + rsum;
}

int get_cnt(int idx)
{
    return query(1, 0, 65536, 0, idx);
}

int get_mid()
{
    int ideal_mid_cnt = (K + 1) / 2;

    int low = 0, high = 65536, mid, result;
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
}

signed main()
{
    scanf("%lld %lld", &N, &K);
    int h = (int)ceil(log2(65536 + 2));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size, 0);

    vector<int> inp(N, 0);
    for (int i = 0; i < N; i++)
        scanf("%lld", &inp[i]);

    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        update(1, 0, 65536, inp[i], 1);
    }
    ans += get_mid();

    for (int i = 0; i < N - K; i++)
    {
        update(1, 0, 65536, inp[i], -1);
        update(1, 0, 65536, inp[i + K], 1);
        ans += get_mid();
    }

    printf("%lld", ans);

    return 0;
}
