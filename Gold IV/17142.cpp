// 17142 연구소 3
// https://www.acmicpc.net/source/39187324

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, idx, mn = 987654321;
int map[52][52];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct block {
    int x;
    int y;
    int time;
} virus[2502], cur;

void bfs() {
    queue <block> q;
    int visited[52][52] = {0,};
    int cnt = 0;
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) {
        if(map[y][x] == 0) cnt++;
        if(map[y][x] == 3) {
            q.push({x,y,0});
            visited[y][x] = 1;
        }
    }
    
    while(!q.empty()) {
        cur = q.front();
        q.pop();

        if(map[cur.y][cur.x] == 0) cnt--;

        if(cnt == 0) break;

        for(int i=0;i<4;i++) {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];
            if(rx <= 0 || ry <= 0 || rx > N || ry > N) continue;
            if(visited[ry][rx] == 0 && map[ry][rx] != 1) {
                visited[ry][rx] = cur.time + 1;
                q.push({rx, ry, cur.time + 1});
            } 
        }
    }
    if(cnt == 0 && mn > cur.time) mn = cur.time;
}

void dfs(int stack, int start) {
    if(stack == M) {
        bfs();
        return;
    }
    for(int i=start;i<idx;i++) {
        map[virus[i].y][virus[i].x] = 3;
        dfs(stack+1, i+1);
        map[virus[i].y][virus[i].x] = 2;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) {
        scanf("%d", &map[y][x]);
        if(map[y][x] == 2) virus[idx++] = {x, y, 0};
    }
    
    dfs(0, 0);
    if(mn == 987654321) printf("-1");
    else printf("%d", mn);
    return 0;
}