// 1931 회의실 배정

#include <bits/stdc++.h>
using namespace std;

int N, cnt, me = -1;
vector<pair<int, int>> schedule;

int main()
{
    scanf("%d", &N);
    for (int i = 0, ta, tb; i < N; i++)
    {
        scanf("%d %d", &ta, &tb);
        schedule.emplace_back(tb, ta);
    }

    sort(schedule.begin(), schedule.end());

    for (auto i : schedule)
    {
        int te = i.first;
        int ts = i.second;
        if (ts >= me)
        {
            cnt++;
            me = te;
        }
    }

    printf("%d", cnt);

    return 0;
}