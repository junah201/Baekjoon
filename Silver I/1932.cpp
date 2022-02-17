// 1932 정수 삼각형
// https://www.acmicpc.net/source/39221031

#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))

int N;
int map[505][505] = {0,};
int DP[505][505] = {0,};

int main() {
    scanf("%d", &N);
    for(int y=1;y<=N;y++) {
        for(int x=1;x<=y;x++) {
            scanf("%d", &map[y][x]);
            DP[y][x] = max(DP[y-1][x], DP[y-1][x-1]) + map[y][x];
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++) if(ans < DP[N][i]) ans = DP[N][i];
    printf("%d", ans);
    return 0;
}