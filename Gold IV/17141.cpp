#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

int N, M, idx, mn = 987654321;
int map[52][52];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct block {
    int x;
    int y;
    int time;
} blink[2502], cur;

void bfs() {
    queue <block> q;
    int visited[52][52] = {0,};
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) if(map[y][x] == 3) {
        q.push({x,y,0});
        visited[y][x] = 1;
    }
    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];
            if(map[ry][rx] == -1) continue;
            if((map[ry][rx] == 0 || map[ry][rx] == 2) && visited[ry][rx] == 0) {
                visited[ry][rx] = 1;
                q.push({rx, ry, cur.time + 1});
            } 
        }
    }
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) if(visited[y][x] == 0 && !(map[y][x] == 1)) return;
    
    if(cur.time < mn) mn = cur.time;
}

void dfs(int stack, int start) {
    if(stack == M) {
        bfs();
        return;
    }
    for(int i=start;i<=idx;i++) {
        map[blink[i].y][blink[i].x] = 3;
        dfs(stack+1, i+1);
        map[blink[i].y][blink[i].x] = 2;
        blink[i].time = 1;
    }
}

int main() {
    for(int i=0;i<52;i++) memset(map[i], -1, sizeof(map[i]));
    scanf("%d %d", &N, &M);
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=N;x++) {
            scanf("%d", &map[y][x]);
            if(map[y][x] == 2) {
                blink[idx++] = {x, y, 0};
            }
        }
    }
    dfs(0, 0);
    if(mn == 987654321) printf("-1");
    else printf("%d", mn);
    return 0;
}