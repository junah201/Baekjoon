#include <stdio.h>
#include <queue>

using namespace std;

int N, M, K;
int map[1002][1002] = {-1,};
int cnt[1002][1002] = {987654321,};
int visited[1002][1002][2] = {0,};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// 0 : 밤, 1 : 낮
struct block {
    int x;
    int y;
    int cnt;
    int dis;
    int day;
} idx, temp;

int bfs() {
    int ans = 987654321;
    queue <block> q;
    q.push({1,1,0,1,1});
    cnt[1][1] = 0;
    while(!q.empty()) {
        idx = q.front();
        q.pop();

        if(idx.x == M && idx.y == N) if(idx.dis < ans) ans = idx.dis;
        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(map[ry][rx] == -1) continue;
            if(idx.cnt + map[ry][rx] > K && idx.day == 1) continue;

            // 벽 and 낮
            if(map[ry][rx] == 1 && idx.day == 1) {
                cnt[ry][rx] = idx.cnt + map[ry][rx];
                q.push({rx, ry, cnt[ry][rx], idx.dis + 1, !idx.day});
            }
            // 길
            else if(map[ry][rx] == 0) {
                cnt[ry][rx] = idx.cnt + map[ry][rx];
                q.push({rx, ry, cnt[ry][rx], idx.dis + 1, !idx.day});
                // 머무르기
                if(visited[idx.y][idx.x][!idx.day] == 0) {
                    visited[idx.y][idx.x][!idx.day] = 1;
                    q.push({idx.x, idx.y, idx.cnt, idx.dis + 1, !idx.day});
                }
            }
        }
    }
    
    if(ans == 987654321) return -1;
    else return ans;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int y=0;y<=N+1;y++) for(int x=0;x<=M+1;x++) map[y][x] = -1;
    for(int y=0;y<=N+1;y++) for(int x=0;x<=M+1;x++) cnt[y][x] = 987654321;
    for(int y=1;y<=N;y++) for(int x=1;x<=M;x++) scanf("%1d", &map[y][x]);
    printf("%d",bfs());
    return 0;
}