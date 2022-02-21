// 14502  연구소
// https://www.acmicpc.net/source/39180132

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, mx, idx;

int map[11][11] = {-1,};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct block {
    int x;
    int y;
} blank[100], e[3];

void bfs();

void dfs(int stack, int start) {
    if (stack == 3) {
        bfs();
        return;
    }
    for(int i=start;i<idx;i++) {
        if(map[blank[i].y][blank[i].x] == 0) {
            map[blank[i].y][blank[i].x] = 1;
            e[stack] = {blank[i].x, blank[i].y};
            dfs(stack + 1, i+1);
            map[blank[i].y][blank[i].x] = 0;
        }
    }
    return;
}

void bfs() {
    int visited[10][10] = {0,};
    queue <block> q;
    for(int y=1;y<=N;y++) for(int x=1;x<=M;x++) if(map[y][x] == 2) {
        q.push({x,y});
        visited[y][x] = 1;
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];
            if(map[ry][rx] == -1) continue;
            if(map[ry][rx] == 0 && visited[ry][rx] == 0) {
                q.push({rx,ry});
                visited[ry][rx] = 1;
            }
        }
    }

    int cnt = 0;
    for(int y=1;y<=N;y++) for(int x=1;x<=M;x++) if(map[y][x] == 0 && visited[y][x] == 0) cnt++;
    if(cnt > mx) mx = cnt;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int y=0;y<=N+1;y++) for(int x=0;x<=M+1;x++) map[y][x] = -1;
    for(int y=1;y<=N;y++) for(int x=1;x<=M;x++) {
        scanf("%d", &map[y][x]);
        if(map[y][x] == 0) {
            blank[idx++] = {x,y};
        }
    }

    dfs(0, 0);

    printf("%d", mx);

    return 0;
}