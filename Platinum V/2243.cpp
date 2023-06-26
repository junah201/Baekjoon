/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
}

signed main()
{
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
