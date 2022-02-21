// 10026  적록색약
// https://www.acmicpc.net/source/39134472

#include <stdio.h>

int N;
int normal[4] = {0,1,2,3};
int blindness[4] = {0,1,1,2};
char map[102][102];
char temp;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y, int (*visited)[102], int *color) {
    visited[y][x] = 1;
    for(int i=0;i<4;i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if(map[y][x] != 0 && color[map[y][x]] == color[map[ry][rx]] && visited[ry][rx] == 0) dfs(rx, ry, visited, color);
    }
}

int search(int *color) {
    int visited[102][102] = {0,};
    int cnt = 0;
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) if(visited[y][x] == 0) {
        dfs(x,y, visited, color);
        cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) {
        scanf(" %1c", &temp);
        if(temp == 'R') map[y][x] = 1;
        else if(temp == 'G') map[y][x] = 2;
        else if(temp == 'B') map[y][x] = 3;
    }
    printf("%d %d", search(normal), search(blindness));
    return 0;
}