// 7562  나이트의 이동
// https://www.acmicpc.net/source/39115266

#include <stdio.h>
#include <queue>

using namespace std;

int T, N;

int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};

struct block {
    int x;
    int y;
    int time = 0;
} input, answer;

int bfs() {
    int visited[302][302] = {0,};
    queue <block> q;
    q.push(input);
    visited[input.y][input.x] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();

        if(idx.x == answer.x && idx.y == answer.y) return idx.time;

        for(int i=0;i<8;i++) {
            int rx = idx.x + dx[i];
            int ry = idx.y + dy[i];
            if(rx >= N || rx < 0 || ry >= N || ry < 0) continue;
            if(visited[ry][rx] == 0) {
                visited[ry][rx] = 1;
                q.push({rx, ry, idx.time + 1});
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        scanf("%d %d", &input.x, &input.y);
        scanf("%d %d", &answer.x, &answer.y);
        printf("%d\n", bfs());
    }
    return 0;
}