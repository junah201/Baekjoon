/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N, M;
int inp[52][52];
int check[52][52];
vector<pair<int, int>> cmd;
queue<tuple<int, int, int>> cloud;

int main()
{
    scanf("%d %d", &N, &M);

    // 격자 입력
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%d", &inp[y][x]);
        }
    }

    // 이동의 정보 입력
    for (int i = 0, d, s; i < M; i++)
    {
        scanf("%d %d", &d, &s);
        cmd.emplace_back(d, s);
    }

    // 초기 구름 입력
    cloud.emplace(N, 1, 0);
    cloud.emplace(N, 2, 0);
    cloud.emplace(N - 1, 1, 0);
    cloud.emplace(N - 1, 2, 0);

    // 초기 구름 이동
    for (int i = 0; i < M; i++)
    {
        while (1)
        {
            auto [x, y, time] = cloud.front();
            if (time != i)
                break;
            cloud.pop();
        }
    }

    return 0;
}