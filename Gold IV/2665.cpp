// 2665  미로만들기
// https://www.acmicpc.net/source/39069454

#include <stdio.h>
#include <queue>

using namespace std;

int N, ans=987654321;
int map[52][52];
int cnt[52][52];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int time;
    int cnt;
} idx;

int bfs() {
    queue <block> q;
    q.push({1,1,0,0});
    int old = -1;
    while(!q.empty()) {
        idx = q.front();
        q.pop();

        old = idx.time;

        if(idx.x == N && idx.y == N) {
            if(idx.cnt < ans) ans = idx.cnt;
            continue;
        }

        for(int i=0;i<4;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(map[ry][rx] != -1 && idx.cnt + !map[ry][rx] < cnt[ry][rx]) {
                cnt[ry][rx] = idx.cnt + !map[ry][rx];
                q.push({rx, ry, idx.time + 1, cnt[ry][rx]});
            }
        }
    }
    return ans;
}

int main() {
    for(int y=0;y<52;y++) for(int x=0;x<52;x++) map[y][x] = -1;
    for(int y=0;y<52;y++) for(int x=0;x<52;x++) cnt[y][x] = 987654321;
    scanf("%d", &N);
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) scanf("%1d", &map[y][x]);
    printf("%d", bfs());
    return 0;
}