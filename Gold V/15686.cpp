// 15686  치킨 배달
// https://www.acmicpc.net/source/39286970

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 987654321, chicken_size;
int map[52][52];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct block {
    int x;
    int y;
    int cnt;
};

vector <block> chicken;
vector <block> home;

void count() {
    int cost[52][52] = {0,};
    for(int y=0;y<52;y++) for(int x=0;x<52;x++) cost[y][x] = 987654321;
    queue <block> q;
    for(auto i : chicken) {
        if(map[i.y][i.x] == 2) {
            q.push({i.x, i.y, 0});
            cost[i.y][i.x] = 0;
        }
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int rx = cur.x + dx[i];
            int ry = cur.y + dy[i];

            if(rx <= 0 || ry <= 0 || rx > N || ry > N) continue;

            if(cost[ry][rx] > cur.cnt + 1) {
                cost[ry][rx] = cur.cnt + 1;
                q.push({rx, ry, cur.cnt + 1});
            }
        }
    }
    int sum = 0;
    
    for(auto i : home) sum += cost[i.y][i.x];
    if(ans > sum) ans = sum;
}

void select(int stact, int start) {
    if(stact == chicken_size - M) {
        count();
        return;
    }
    if(start == chicken.size()) return;
    for(int i=start;i<chicken_size;i++) {
        map[chicken[i].y][chicken[i].x] = 0;
        select(stact + 1, i + 1);
        map[chicken[i].y][chicken[i].x] = 2;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        scanf("%d", &map[i][j]);
        if(map[i][j] == 2) chicken.push_back({j, i, 0});
        else if(map[i][j] == 1) home.push_back({j, i, 0});
    }
    chicken_size = chicken.size();
    select(0,0);
    printf("%d", ans);
    return 0;
}