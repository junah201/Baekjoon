// 2178 미로 탐색
// https://www.acmicpc.net/source/39112920

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[102][102] = {-1,};
int visited[102][102] = {0,};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int time;
};

int bfs() {
    queue <block> q;
    q.push({1,1,1});
    visited[1][1] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        if(idx.x == M && idx.y == N) return idx.time;
        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(map[ry][rx] == 1 && visited[ry][rx] == 0) {
                visited[ry][rx] = 1;
                q.push({rx, ry, idx.time + 1});
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int y=1;y<=N;y++) for(int x=1;x<=M;x++) scanf("%1d", &map[y][x]);
    printf("%d", bfs());
    return 0;
}