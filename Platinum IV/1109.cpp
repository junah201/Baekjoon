/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
int X, Y;

char inp[60][60];
int color[60][60];
int visited[60][60];
int parent[3000];
bool check[3000];
vector<int> child[3000];
stack<int> ans;
int result;
int height[3000];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int dfs(int now)
{
    int ret = -1;

    for (int i = 0; i < child[now].size(); i++)
    {
        ret = max(ret, dfs(child[now][i]));
    }

    return ret + 1;
}

void land_dfs(int x, int y, int idx)
{
    color[y][x] = idx;

    for (int i = 0; i < 8; i++)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
            continue;

        if (color[ry][rx] != -1)
            continue;

        if (inp[ry][rx] != 'x')
            continue;

        land_dfs(rx, ry, idx);
    }
}

int main()
{
    // 기본값 설정 & 입력
    for (int i = 0; i < 3000; i++)
        parent[i] = INT_MAX;

    scanf("%d %d", &Y, &X);

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            scanf(" %c", &inp[y][x]);
            color[y][x] = -1;
        }
    }

    // 섬에 번호 붙이기
    int land_idx = 0;
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x] == 'x' && color[y][x] == -1)
            {
                land_dfs(x, y, land_idx);
                land_idx++;
            }
        }
    }

    stack<pair<pair<int, int>, int>> escape_st;
    vector<pair<int, int>> start;

    // 섬에 대해서 탐색
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (inp[y][x] == 'x' && !check[color[y][x]])
            {
                check[color[y][x]] = true;
                start.emplace_back(x, y);
            }
        }
    }

    for (int i = 0; i < start.size(); i++)
    {
        for (int y = 0; y < 52; y++)
        {
            for (int x = 0; x < 52; x++)
            {
                visited[y][x] = false;
            }
        }

        escape_st.emplace(make_pair(start[i].first, start[i].second), color[start[i].second][start[i].first]);

        while (!escape_st.empty())
        {
            auto [nowx, nowy] = escape_st.top().first;
            int nowcolor = escape_st.top().second;
            escape_st.pop();

            visited[nowy][nowx] = true;

            for (int j = 0; j < 4; j++)
            {
                int rx = nowx + dx[j];
                int ry = nowx + dy[j];

                if (rx < 0 || rx >= X || ry < 0 || ry >= Y)
                {
                    parent[nowcolor] = -1;
                    continue;
                }

                if (visited[ry][rx])
                    continue;

                if (inp[ry][rx] == 'x' && color[ry][rx] != nowcolor)
                {
                    parent[nowcolor] = min(parent[nowcolor], color[ry][rx]);
                    continue;
                }

                escape_st.emplace(make_pair(rx, ry), nowcolor);
            }
        }
    }

    for (int i = 0; i < land_idx; i++)
    {
        if (parent[i] != -1)
        {
            child[parent[i]].push_back(i);
        }
    }

    int max_depth = -1;

    for (int i = 0; i < land_idx; i++)
    {
        int h = dfs(i);
        max_depth = max(max_depth, h);
        height[h]++;
    }

    if (max_depth <= -1)
    {
        printf("-1");
        return 0;
    }

    for (int i = 0; i <= max_depth; i++)
    {
        printf("%d ", height[i]);
    }

    printf("\n");
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            printf("%3d ", color[y][x]);
        }
        printf("\n");
    }

    return 0;
}