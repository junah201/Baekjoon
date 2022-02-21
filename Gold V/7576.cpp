// 7576  토마토
// https://www.acmicpc.net/source/38847664

#include <stdio.h>
#include <queue>

using namespace std;

int x, y;
int map[1002][1002];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int time;
};

int bfs() {
    queue <block> q;
    for(int ty=1;ty<=y;ty++) {
        for(int tx=1;tx<=x;tx++) {
            if(map[ty][tx]==1) {
                struct block temp;
                temp.x = tx;
                temp.y = ty;
                temp.time = 0;
                q.push(temp);
            }
        }
    }
    
    struct block idx;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            if(map[idx.y+dy[i]][idx.x+dx[i]]==0) {
                map[idx.y+dy[i]][idx.x+dx[i]] = 1;
                struct block temp;
                temp.x = idx.x+dx[i];
                temp.y = idx.y+dy[i];
                temp.time = idx.time+1;
                q.push(temp);
            }
        }
    }
    return idx.time;
}

int main() {
    for(int ty=0;ty<=1001;ty++) {
        for(int tx=0;tx<=1001;tx++) {
            map[ty][tx] = -1;
        }
    }
    scanf("%d %d", &x, &y);
    for(int ty=1;ty<=y;ty++) {
        for(int tx=1;tx<=x;tx++) {
            scanf("%d", &map[ty][tx]);
        }
    }

    int ans = bfs();
    for(int ty=1;ty<=y;ty++) {
        for(int tx=1;tx<=x;tx++) {
            if(map[ty][tx]==0) {
                printf("-1");
                return 0;
            };
        }
    }
    printf("%d", ans);
    return 0;
}