#include <bits/stdc++.h>
using namespace std;

int N, M, ans, cnt = 2;
int inp[12][12];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int p[10];

struct node
{
    int start, end, dis;
};

vector<node> v;

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    p[fin(a)] = fin(b);
}

void dfs(int x, int y, int value)
{
    inp[y][x] = value;
    for (int i = 0; i < 4; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (rx < 0 || rx >= 10 || ry < 0 || ry >= 10)
            continue;
        if (inp[ry][rx] == 1)
            dfs(rx, ry, value);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%d", &inp[y][x]);

    for (int i = 0; i < 10; i++)
        p[i] = i;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (inp[y][x] == 1)
                dfs(x, y, cnt++);
    /*
    for(int y=0;y<N;y++) {
        for(int x=0;x<M;x++)
            printf("%d", inp[y][x]);
        printf("\n");
    }
*/
    // 세로 다리
    for (int x = 0; x < M; x++)
    {
        int start = 0, end = 0, dis = 0;
        for (int y = 0; y < N; y++)
        {
            // 시작 도시
            if (!start && inp[y][x])
                start = inp[y][x];
            else if (start && inp[y][x] == start && dis)
                dis = 0;
            // 끝 도시
            else if (start && inp[y][x] && inp[y][x] != start)
            {
                end = inp[y][x];
                if (dis > 1)
                    v.push_back({start, end, dis});
                start = end, dis = 0, end = 0;
            }
            // 길이
            else if (start && !end && inp[y][x] != start)
                dis++;
        }
    }

    // 가로 다리
    for (int y = 0; y < N; y++)
    {
        int start = 0, end = 0, dis = 0;
        for (int x = 0; x < M; x++)
        {
            // 시작 도시
            if (!start && inp[y][x])
                start = inp[y][x];
            else if (start && inp[y][x] == start && dis)
                dis = 0;
            // 끝 도시
            else if (start && inp[y][x] && inp[y][x] != start)
            {
                end = inp[y][x];
                if (dis > 1)
                    v.push_back({start, end, dis});
                start = end, dis = 0, end = 0;
            }
            // 길이
            else if (start && !end && start != inp[y][x])
                dis++;
        }
    }
    /*
        for(auto i : v)
            printf("%d %d - %d\n", i.start, i.end, i.dis);
    */
    sort(v.begin(), v.end(), [](struct node a, struct node b)
         { return a.dis < b.dis; });

    for (auto i : v)
    {
        int start = i.start, end = i.end, dis = i.dis;
        if (fin(i.start) == fin(i.end))
            continue;
        ans += i.dis;
        uni(start, end);
    }

    for (int i = 3; i < cnt; i++)
        if (fin(2) != fin(i))
        {
            printf("-1");
            return 0;
        }

    printf("%d", ans);
    return 0;
}
