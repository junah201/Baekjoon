#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 0;

priority_queue<pair<int, int>> 주차장;
queue<int> 대기줄;

int car[2002][3];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, cost; i < N; i++)
    {
        scanf("%d", &cost);
        주차장.push({-i, cost});
    }

    for (int i = 1, 차무게; i <= M; i++)
    {
        scanf("%d", &차무게);
        car[i][0] = 차무게;
    }
    for (int i = 1, 차번호; i <= 2 * M; i++)
    {
        scanf("%d", &차번호);
        if (차번호 > 0)
        {
            if (주차장.empty())
            {
                대기줄.push(차번호);
            }
            else
            {
                auto [주자창번호, 주차장가격] = 주차장.top();
                car[차번호][1] = 주차장가격;
                car[차번호][2] = 주자창번호;
                주차장.pop();
            }
        }
        else
        {
            주차장.push({car[-차번호][2], car[-차번호][1]});
            ans += car[-차번호][0] * car[-차번호][1];
            if (!대기줄.empty())
            {
                차번호 = 대기줄.front();
                대기줄.pop();
                auto [주자창번호, 주차장가격] = 주차장.top();
                car[차번호][1] = 주차장가격;
                car[차번호][2] = 주자창번호;
                주차장.pop();
            }
        }
    }
    printf("%d", ans);
    return 0;
}