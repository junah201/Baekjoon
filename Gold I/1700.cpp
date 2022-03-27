#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
// inp : 입력값, exist : 해당 플러그가 꼽혀있느지
vector<int> inp, exist;
// 플러그 마다 몇번째 인덱스에 꼽혀있는지
vector<deque<int>> cnt;

deque<int> pq;

/*
bool cmp(int a, int b)
{
    if (cnt[a].empty() != cnt[b].empty())
        return cnt[a].empty();
    if (cnt[a].empty())
        return false;
    return cnt[a].front() > cnt[b].front();
}
*/

bool cmp(int a, int b)
{
    if (cnt[a].empty() && cnt[b].empty())
        return false;
    if (cnt[a].empty() != cnt[b].empty())
        return cnt[a].empty();
    return cnt[a].front() > cnt[b].front();
}

int main()
{
    scanf("%d %d", &N, &K);
    inp.resize(K + 10);
    cnt.resize(K + 10);
    exist.resize(K + 10, 0);
    for (int i = 1; i <= K; i++)
    {
        scanf("%d", &inp[i]);
        cnt[inp[i]].push_back(i);
    }

    // 초기 플러그
    for (int i = 1; i <= K; i++)
    {
        // 정렬 (가장 늦게 다시 사용할 전기 용품을 가장 엎으로 가도록 정렬)
        sort(pq.begin(), pq.end(), cmp);

        if (!cnt[inp[i]].empty())
            cnt[inp[i]].pop_front();

        // 이미 들어있으면
        if (exist[inp[i]])
            continue;
        // 들어있지 않으면서, 넣을 공간이 있으면
        else if (pq.size() < N)
        {
            exist[inp[i]] = 1;
            pq.push_back(inp[i]);
        }
        // 들어있지 않으면서, 넣을 공간이 없으면
        else
        {
            ans++;

            int cur = pq.front();
            pq.pop_front();

            exist[cur] = 0;
            exist[inp[i]] = 1;
            pq.push_back(inp[i]);
        }
    }

    printf("%d", ans);
    return 0;
}