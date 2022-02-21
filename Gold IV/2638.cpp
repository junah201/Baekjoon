// 2638  치즈
// https://www.acmicpc.net/source/38990693

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[102][102];
int cnt[102][102];
int check[102][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int time;
} temp, idx;

queue <block> q;

int dfs(int x, int y, int time) {
    if(x==0 || y==0 || x==M+1 || y==N+1) return -1;
    if(map[y][x] == 1) cnt[y][x]++;
    if(cnt[y][x] >= 2) {
        temp.x = x;
        temp.y = y;
        temp.time = time;
        cnt[y][x] = -999;
        q.push(temp);
        return 0;
    }
    if(check[y][x] == 1) return 0;
    else check[y][x] = 1;
    if(map[y][x] == 1) return 0;
    for(int i=0;i<4;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        dfs(rx, ry, time);
    }
    check[y][x] = 1;
    return 0;
}

int bfs() {
    dfs(1,1,1);
    if(q.empty()) return 0;
    while(!q.empty()) {
        idx = q.front();
        map[idx.y][idx.x] = 0;
        cnt[idx.y][idx.x] = 0;
        check[idx.y][idx.x] = 0;
        q.pop();
        dfs(idx.x, idx.y, idx.time+1);
    }
    return idx.time;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d", &map[i][j]);
    printf("%d", bfs());
    return 0;
}