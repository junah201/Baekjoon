#include <stdio.h>
#include <queue>
#define abs(_x) ((_x) > 0 ? (_x) : -(_x))

using namespace std;

int N, M;
int map[72][102];
int visited[72][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int cnt;

int bfs(int x, int y) {
    queue <pair<int, int>> q;
    q.emplace(x, y);
    visited[y][x] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int rx = cur.first + dx[i];
            int ry = cur.second + dy[i];

            if(rx < 0 || ry < 0 || rx >= N || ry >= M) continue;
            if(abs(map[y][x] - map[ry][rx]) <= 1 && visited[ry][rx] == 0) {
                visited[ry][rx] = 1;
                q.emplace(rx, ry);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int y=0;y<M;y++) for(int x=0;x<N;x++) scanf("%d", &map[y][x]);
    for(int y=0;y<M;y++) for(int x=0;x<N;x++) {
        if(map[y][x] != 0 && visited[y][x] == 0) {
            printf("%d %d\n", x, y);
            bfs(x, y);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}