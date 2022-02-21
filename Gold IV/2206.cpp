// 2206 벽 부수고 이동하기
// https://www.acmicpc.net/source/39105270

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[1002][1002] = {-1,};
int cnt[1002][1002] = {987654321,};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int cnt;
    int dis;
} idx, temp;

int bfs() {
    int ans = 987654321;
    queue <block> q;
    q.push({1,1,0,1});
    cnt[1][1] = 0;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        if(idx.x == M && idx.y == N) if(idx.dis < ans) ans = idx.dis;
        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(map[ry][rx] == -1) continue;
            if(idx.cnt + map[ry][rx] > 1) continue;
            if(idx.cnt + map[ry][rx] < cnt[ry][rx]) {
                cnt[ry][rx] = idx.cnt + map[ry][rx];
                q.push({rx, ry, cnt[ry][rx], idx.dis + 1});
            }
        }
    }
    if(ans == 987654321) return -1;
    else return ans;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int y=0;y<=N+1;y++) for(int x=0;x<=M+1;x++) map[y][x] = -1;
    for(int y=0;y<=N+1;y++) for(int x=0;x<=M+1;x++) cnt[y][x] = 987654321;
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=M;x++) {
            scanf("%1d", &map[y][x]);
        }
    }
    printf("%d",bfs());
    return 0;
}