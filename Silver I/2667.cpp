// 2667 단지번호붙이기
// https://www.acmicpc.net/source/39106643

#include <stdio.h>
#include <algorithm>

int N;
int map[27][27];
int visited[27][27];
int ids[1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y, int id) {
    visited[y][x] = 1;
    ids[id]++;
    for(int i=0;i<4;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if(visited[ry][rx] != 0 || map[ry][rx] == 0) continue;
        dfs(rx, ry, id);
    }
}

int main() {
    scanf("%d", &N);
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) scanf("%1d", &map[y][x]);
    int cnt = 0;
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=N;x++) {
            if(map[y][x] == 1 && visited[y][x] == 0) {
                cnt++;
                dfs(x, y, cnt);
            }
        }
    }
    printf("%d\n", cnt);
    std::sort(ids+1, ids+cnt+1);
    for(int i=1;i<=cnt;i++) printf("%d\n",ids[i]);
    return 0;
}