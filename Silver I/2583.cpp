// 2583 영역 구하기
// https://www.acmicpc.net/source/39696671

#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int inp[102][102];
int cnt;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> v;

int bfs(int x, int y)
{
    int result = 0;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    inp[y][x] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        result++;
        for (int i = 0; i < 4; i++)
        {
            int rx = cur.first + dx[i];
            int ry = cur.second + dy[i];
            if (rx < 0 || ry < 0 || rx >= M || ry >= N)
                continue;
            if (inp[ry][rx] == 0)
            {
                inp[ry][rx] = 1;
                q.emplace(rx, ry);
            }
        }
    }
    return result;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0, x1, y1, x2, y2; i < K; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
                inp[y][x] = 1;
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (!inp[y][x])
            {
                v.push_back(bfs(x, y));
                cnt++;
            }

    sort(v.begin(), v.end());
    printf("%d\n", cnt);
    for (auto i : v)
        printf("%d ", i);
    return 0;
}