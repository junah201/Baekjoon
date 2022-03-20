#include <bits/stdc++.h>
using namespace std;

int N, M, MAX, SUM;
vector<int> marble;
int ans1 = INT_MAX;
vector<int> ans2;
vector<int> ans3;

pair<vector<int>, vector<int>> cal(int key)
{
    int idx = 0, value = 0;
    vector<int> tmp;
    vector<int> tmp2;
    tmp.resize(1, 0);
    tmp2.resize(1, 0);
    for (auto i : marble)
    {
        if (value + i > key)
        {
            value = 0;
            idx++;
            tmp.push_back(0);
            tmp2.push_back(0);
        }
        value += i;
        tmp[idx]++;
        tmp2[idx] += i;
    }

    return {tmp, tmp2};
}

int bs()
{
    int low = MAX, high = SUM, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        auto [div, div2] = cal(mid);

        if (div.size() <= M)
        {
            if (ans1 > mid)
            {
                ans1 = mid;
                ans2 = div;
                ans3 = div2;
            }

            if (high == mid)
                high = mid - 1;
            else
                high = mid;
        }
        else if (div.size() > M)
            low = mid + 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    marble.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &marble[i]);
        SUM += marble[i];
        MAX = max(MAX, marble[i]);
    }
    bs();
    printf("%d\n", ans1);
    if (ans2.size() == M)
    {
        for (auto i : ans2)
            printf("%d ", i);
        return 0;
    }
    int cnt = ans2.size();
    for (int i = 0; i < ans2.size(); i++)
    {
        while (ans2[i] > 1 && cnt < M)
        {
            printf("1 ");
            ans2[i]--;
            cnt++;
        }
        printf("%d ", ans2[i]);
    }
    return 0;
}