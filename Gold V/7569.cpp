// 7569  토마토
// https://www.acmicpc.net/source/38847197

#include <stdio.h>
#include <queue>

using namespace std;

int x, y, z;
int map[102][102][102];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct block {
    int x;
    int y;
    int z;
    int time=0;
};

int bfs() {
    queue <block> q;
    for(int tz=1;tz<=z;tz++) {
        for(int ty=1;ty<=y;ty++) {
            for(int tx=1;tx<=x;tx++) {
                if(map[tz][ty][tx]==1) {
                    struct block temp;
                    temp.x = tx;
                    temp.y = ty;
                    temp.z = tz;
                    temp.time = 0;
                    q.push(temp);
                }
            }
        }
    }
    struct block idx;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        for(int i=0;i<6;i++) {
            if(map[idx.z+dz[i]][idx.y+dy[i]][idx.x+dx[i]]==0) {
                map[idx.z+dz[i]][idx.y+dy[i]][idx.x+dx[i]] = 1;
                struct block temp;
                temp.x = idx.x+dx[i];
                temp.y = idx.y+dy[i];
                temp.z = idx.z+dz[i];
                temp.time = idx.time+1;
                q.push(temp);
            }
        }
    }
    return idx.time;
}

int main() {
    for(int tz=0;tz<=101;tz++) {
        for(int ty=0;ty<=101;ty++) {
            for(int tx=0;tx<=101;tx++) {
               map[tz][ty][tx] = -1;
            }
        }
    }
    scanf("%d %d %d", &x, &y, &z);
    for(int tz=1;tz<=z;tz++) {
        for(int ty=1;ty<=y;ty++) {
            for(int tx=1;tx<=x;tx++) {
                scanf("%d", &map[tz][ty][tx]);
            }
        }
    }

    int ans = bfs();
    for(int tz=1;tz<=z;tz++) {
        for(int ty=1;ty<=y;ty++) {
            for(int tx=1;tx<=x;tx++) {
                if(map[tz][ty][tx]==0) {
                    printf("-1");
                    return 0;
                };
            }
        }
    }
    printf("%d", ans);
    return 0;
}