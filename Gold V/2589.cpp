// 2589  보물섬
// https://www.acmicpc.net/source/39111919

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
char map[52][52] = {-1,};
int check[52][52];
int ans;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int dis;
} mx;

void bfs(int x, int y) {
    int visited[52][52] = {0,};
    for(int x=1;x<=N;x++) {
        for(int y=1;y<=M;y++) {
            visited[y][x] = 987654321;
        }
    }
    queue <block> q;
    q.push({x, y, 0});
    visited[y][x] = 0;
    mx.dis = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        if(idx.dis > mx.dis) mx = idx;
        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(map[ry][rx] == 'L' && visited[ry][rx] > idx.dis + 1) {
                q.push({rx, ry, idx.dis + 1});
                check[ry][rx] = 1;
                visited[ry][rx] = idx.dis + 1;
            }
        }
    } 
}


int main() {
    scanf("%d %d", &N, &M);
    for(int x=1;x<=N;x++) {
        for(int y=1;y<=M;y++) {
            scanf(" %c", &map[y][x]);
        }
    }

    for(int x=1;x<=N;x++) {
        for(int y=1;y<=M;y++) {
            if(map[y][x] == 'L') {
                bfs(x, y);
                if(mx.dis > ans) ans = mx.dis;
            }
        }
    }
    printf("%d", ans);
    return 0;
}