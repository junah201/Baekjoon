// 2636 치즈
// https://www.acmicpc.net/source/39081091

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, orgin_cnt, now_cnt;
int map[102][102];
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
    if(map[y][x] == 1) {
        q.push({x,y,time});
        return 0;
    }
    if(check[y][x] == 1) return 0;
    check[y][x] = 1;
    if(map[y][x] == 1) return 0;
    for(int i=0;i<4;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        dfs(rx, ry, time);
    }
    return 0;
}

int bfs() {
    dfs(1,1,0);
    if(q.empty()) return 0;
    int orgin_time = -1;
    now_cnt = orgin_cnt;
    idx.time = 0;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        if(orgin_time != idx.time) {
            orgin_cnt = now_cnt;
            now_cnt = 0;
            for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) now_cnt += map[i][j];
        }
        orgin_time = idx.time;

        map[idx.y][idx.x] = 0;
        check[idx.y][idx.x] = 0;
        dfs(idx.x, idx.y, idx.time+1);
    }
    if(orgin_cnt!=0 && idx.time == 0) idx.time = 1;
    return idx.time;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++) {
            scanf("%d", &map[i][j]);
            orgin_cnt += map[i][j];
        }
    bfs();
    printf("%d\n%d\n",idx.time, orgin_cnt);
    return 0;
}