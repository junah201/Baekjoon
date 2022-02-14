// 2638  치즈
// 

#include <stdio.h>


int N, M;
int map[102][102];
int cnt[102][102];
int check[102][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
    

struct block{
    int x;
    int y;
    int time;
};

void dfs(int x, int y) {
    printf("dfs %d %d\n", x,y);
    if(x==0 || y==0 || x>M || y>N) return;
    if(map[y][x] == 1) {
        printf("맵1 리턴\n");
        cnt[y][x]++;
        return;
    };
    if(check[y][x]) {
        printf("첵 리턴\n");
        return;
    }
    check[y][x] = 1;
    for(int i=0;i<4;i++) if(check[y+dy[i]][x+dx[i]]==0) dfs(x+dx[i], y+dy[i]);
    return;
}

int is_empty() {
    int result = 0;
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=M;x++) {
            result+=map[y][x];
        }
    }
    return result;
}

int bfs() {
    int ans = 0;
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=M;x++) {
            if(cnt[y][x]>=2) {
                check[y][x] = 2;
                map[y][x] = 0;
            }
            cnt[y][x] = 0;
        }
    }
    ans++;
    while(is_empty()) {
        dfs(1,1);
        for(int y=1;y<=N;y++) {
            for(int x=1;x<=M;x++) {
                if(cnt[y][x]>=2) {
                    check[y][x] = 2;
                    map[y][x] = 0;
                }
                cnt[y][x] = 0;
            }
        }
        ans++;
    }
    return ans;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int y=1;y<=N;y++) 
        for(int x=1;x<=M;x++)
            scanf("%d",&map[y][x]);

    for(int y=1;y<=N;y++) {
        for(int x=1;x<=M;x++) {
            if(map[y][x] == 1) printf("■");
            else printf("□");
        }
        printf("\n");
    }
    printf("\n");
    
    dfs(1,1);
    printf("%d\n",bfs());
    return 0;
}