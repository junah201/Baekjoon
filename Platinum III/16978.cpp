#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

struct xy
{
    int k;
    int i;
    int j;
    int idx;
    ull value;
};

vector<pair<int, int>> one;
vector<xy> two;

ull inp[1000001], divsum[10020][101];
ull N, M, a, b, c;

void queries_one(int idx)
{
    auto [b1, c1] = one[idx];
    inp[b1] = c1;
    for (int i = 1; i <= 100; i++)
        divsum[b1 / 100][i] = divsum[b1 / 100][i - 1] + inp[b1 - b1 % 100 + i - 1];
}

ull queries_two(int idx)
{
    auto [_, b2, c2, __, ___] = two[idx];
    ull result = 0;
    if (b2 / 100 == c2 / 100)
        result = divsum[c2 / 100][c2 % 100 + 1] - divsum[b2 / 100][b2 % 100];
    else
    {
        result = divsum[c2 / 100][c2 % 100 + 1] + divsum[b2 / 100][100] - divsum[b2 / 100][b2 % 100];
        for (int i = b2 / 100 + 1; i < c2 / 100; i++)
            result += divsum[i][100];
    }
    return result;
}

int main()
{
    scanf("%llu", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%llu", &inp[i]);
        divsum[i / 100][i % 100 + 1] = divsum[i / 100][i % 100] + inp[i];
    }
    scanf("%llu", &M);
    for (int h = 0, cmd, a, b, c; h < M; h++)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            scanf("%d %d", &a, &b);
            one.push_back({a, b});
        }
        else if (cmd == 2)
        {
            scanf("%d %d %d", &a, &b, &c);
            two.push_back({a, b, c, h, 0});
        }
    }
    sort(two.begin(), two.end(), [](struct xy a, struct xy b)
         { return a.k < b.k; });

    int one_size = one.size();
    int two_idx = 0;
    int two_size = two.size();
    while (two[two_idx].k == 0)
    {
        two[two_idx].value = queries_two(two_idx);
        two_idx++;
    }

    for (int u = 0; u < one_size; u++)
    {
        queries_one(u);

        while (two[two_idx].k == u + 1)
        {
            two[two_idx].value = queries_two(two_idx);
            two_idx++;
        }
    }

    while (two[two_idx].k == one_size)
    {
        two[two_idx].value = queries_two(two_idx);
        two_idx++;
    }
    sort(two.begin(), two.end(), [](struct xy a, struct xy b)
         { return a.idx < b.idx; });

    for (int i = 0; i < two_size; i++)
        printf("%llu\n", two[i].value);

    return 0;
}