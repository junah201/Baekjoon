// 4963  섬의 개수
// https://www.acmicpc.net/source/39131834

#include <stdio.h>

int W, H;
int map[52][52];
int visited[52][52];

int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

void dfs(int x, int y) {
    visited[y][x] = 1;
    for(int i=0;i<8;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if(visited[ry][rx] != 0 || map[ry][rx] == 0) continue;
        dfs(rx, ry);
    }
}

int main() {
    while(1) {
        scanf("%d %d", &W, &H);
        if(W==0 && H==0) break;
        for(int y=0;y<=H+1;y++) for(int x=0;x<=W+1;x++) map[y][x] = 0;
        for(int y=0;y<=H+1;y++) for(int x=0;x<=W+1;x++) visited[y][x] = 0;
        for(int y=1;y<=H;y++) for(int x=1;x<=W;x++) scanf("%d", &map[y][x]);
        int cnt = 0;
        for(int y=1;y<=H;y++) {
            for(int x=1;x<=W;x++) {
                if(map[y][x] == 1 && visited[y][x] == 0) {
                    cnt++;
                    dfs(x, y);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}