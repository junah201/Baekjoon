#include <bits/stdc++.h>
using namespace std;

int T;
priority_queue<pair<int, int>> cnt;
int lake[1000005], rain[1000005];
queue<int> result;

/*
bool cmp(int a, int b)
{
    if (cnt[a].empty() && cnt[b].empty())
        return false;
    if (cnt[a].empty() != cnt[b].empty())
        return cnt[a].empty();
    return cnt[a].front() > cnt[b].front();
}
*/

int solve()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> pq;
    // 입력
    for (int i = 0, tmp; i < M; i++)
    {
        scanf("%d", &rain[i]);
        if (rain[i])
            cnt.emplace(i, rain[i]);
    }

    // result 초기화
    while (!result.empty())
        result.pop();

    // pq 값 넣기
    for (int i = 1; i <= N; i++)
        pq.push_back(i);

    // 계산
    for (int i = 0; i < M; i++)
    {
        /*
        printf("%d\n", cmp(1, 2));
        printf("rain: %d\n", rain[i]);
        printf("front: %d ; size: %lu\n", pq.front(), pq.size());
        printf("lake: %d %d\n", lake[1], lake[2]);
        */
        // 비가 오면
        if (rain[i])
        {
            // 호수에 이미 물이 있으면
            if (lake[rain[i]])
            {
                printf("NO\n");
                return 0;
            }
            // 호수가 비어 있으면
            lake[rain[i]] = 1;
            pq.push_back(rain[i]);
        }
        // 비가 안오면
        else
        {
            // 먹을 물이 없으면
            if (pq.empty())
                result.push(0);
            // 먹을 물이 있으면
            else
            {
                while (!cnt.empty())
                {
                    auto [day, loc] = cnt.top();

                    if (lake[loc] == 0)
                        cnt.pop();
                    else
                        break;
                }

                auto [day, loc] = cnt.top();
                cnt.pop();

                lake[loc] = 0;
                result.push(loc);
            }
            /*
            printf("end = \n");
            printf("%d : %d ; %lu\n", i, pq.front(), pq.size());
            printf("%d %d\n", lake[1], lake[2]);
            */
        }
    }
    printf("YES\n");
    while (!result.empty())
    {
        printf("%d ", result.front());
        result.pop();
    }
    printf("\n");

    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--)
        solve();

    return 0;
}