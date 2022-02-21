// 2468 안전 영역
// https://www.acmicpc.net/source/39133692

#include <stdio.h>

int N, temp, min=987654321, max=0, ans, cnt;

int map[102][102];
int visited[102][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y, int w) {
    visited[y][x] = 1;
    for(int i=0;i<4;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if(map[ry][rx] >= w && visited[ry][rx] == 0) dfs(rx, ry, w);
    }
}

int main() {
    scanf("%d", &N);
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=N;x++) {
            scanf("%d", &map[y][x]);
            if(max < map[y][x]) max = map[y][x];
            if(min > map[y][x]) min = map[y][x];
        }
    }

    for(int i=min;i<=max;i++) {
        for(int i=0;i<102;i++) for(int j=0;j<102;j++) visited[i][j] = 0;
        cnt = 0;
        for(int y=1;y<=N;y++) {
            for(int x=1;x<=N;x++) {
                if(map[y][x] >= i && visited[y][x] == 0) {
                    dfs(x,y, i);
                    cnt++;
                }
            }
        }
        if(ans < cnt) ans = cnt;
    }
    printf("%d", ans);
    return 0;
}