// 1012  유기농 배추
// https://www.acmicpc.net/source/39114494

#include <stdio.h>
#include <queue>

using namespace std;

int T, M, N, K;

int cnt;

int map[52][52];
int visited[52][52];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
};

void bfs(int x, int y) {
    queue <block> q;
    q.push({x, y});
    visited[y][x] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(rx < 0 || ry < 0) continue;
            if(map[ry][rx] == 1 && visited[ry][rx] == 0) {
                visited[ry][rx] = 1;
                q.push({rx, ry});
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=0;i<52;i++) for(int j=0;j<52;j++) map[i][j] = 0;
        for(int i=0;i<52;i++) for(int j=0;j<52;j++) visited[i][j] = 0;
        scanf("%d %d %d", &M, &N, &K);
        int t1, t2;
        while(K--) {
            scanf("%d %d", &t1, &t2);
            map[t2][t1] = 1;
        }
        cnt = 0;
        for(int y=0;y<N;y++) {
            for(int x=0;x<M;x++) {
                if(map[y][x] == 1 && visited[y][x] == 0) {
                    cnt++;
                    bfs(x, y);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}