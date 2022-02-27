#include <bits/stdc++.h>
using namespace std;

int R, C, car_idx = 1, parking_idx = 1;
char inp[102][102];
int inp_idx[102][102];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct info
{
    int x;
    int y;
    int time;
    int id;
};

queue<info> q;

vector<vector<int>> arrived;

/*
1 : A, B
2 : B, C
3 : A

1 : B
2 : C
3 : A
*/

bool is_complete() {
    vector<int> selected;
    vector<int> check;
    selected.resize(car_idx);
    check.resize(parking_idx);
    for (int i = 0;i < car_idx;i++) {
        if (arrived[car_idx].size() == 1) {
            selected[car_idx] = arrived[car_idx][0];
            check[arrived[car_idx][0]] = 1;
        }
    }
}

int bfs(vector<vector<vector<int>>>& visited)
{
    while (!q.empty())
    {
        auto [x, y, time, id] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx < 0 || ry < 0 || rx >= C || ry >= R)
                continue;
            if (inp[ry][rx] == 'X')
                continue;
            if (visited[id][ry][rx])
                continue;
            visited[id][ry][rx] = 1;
            q.push({ rx, ry, time + 1, id });
            if (inp[ry][ry] == 'C') {
                arrived[id].push_back(inp_idx[ry][rx]);
                if (is_complete()) return time;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &R, &C);
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++)
        {
            scanf(" %c", &inp[y][x]);
            if (inp[y][x] == 'C')
                q.push({ x, y, 0, car_idx++ });
            else if (inp[y][x] == 'P')
                inp_idx[y][x] = parking_idx++;
        }

    vector<vector<vector<int>>> visited(car_idx, vector<vector<int>>(R, vector<int>(C)));
    arrived.resize(car_idx);

    bfs(visited);
    return 0;
}