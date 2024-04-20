/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF INT_MAX

vector<int> a;
// 구간 전체합, 왼쪽 범위에서 왼쪽부터 오는 합, 오른쪽 범위에서 오른쪽부터 오는 합, 정답, 구간 내 최대값
vector<tuple<int, int, int, int>> tree;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = {a[start], a[start], a[start], a[start]};
        return;
    }

    int mid = (start + end) / 2;

    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    auto [l_total_sum, l_l_sum, l_r_sum, l_ans] = tree[node * 2];
    auto [r_total_sum, r_l_sum, r_r_sum, r_ans] = tree[node * 2 + 1];

    tree[node] = {
        l_total_sum + r_total_sum,
        max(l_l_sum, l_total_sum + r_l_sum),
        max(r_r_sum, r_total_sum + l_r_sum),
        max({l_ans,
             r_ans,
             l_r_sum + r_l_sum})};
}

tuple<int, int, int, int> query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return {0, -INF, -INF, -INF};
    if (left <= start && end <= right)
        return tree[node];

    auto [l_total_sum, l_l_sum, l_r_sum, l_ans] = query(node * 2, start, (start + end) / 2, left, right);
    auto [r_total_sum, r_l_sum, r_r_sum, r_ans] = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return {
        l_total_sum + r_total_sum,
        max(l_l_sum, l_total_sum + r_l_sum),
        max(r_r_sum, r_total_sum + l_r_sum),
        max({l_ans,
             r_ans,
             l_r_sum + r_l_sum})};
}

signed main()
{
    int N, M;
    scanf("%lld", &N);
    a.resize(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size, {0, 0, 0, -INF});

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
    }

    init(1, 0, N - 1);

    scanf("%lld", &M);
    while (M--)
    {
        int s, e;
        scanf("%lld %lld", &s, &e);
        auto [total_sum, l_sum, r_sum, ans] = query(1, 0, N - 1, s - 1, e - 1);
        printf("%lld\n", ans);
    }

    return 0;
}