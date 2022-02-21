// 14889 스타크와 링크
// https://www.acmicpc.net/source/39419515

#include <stdio.h>
#define	abs(x) (((x)<0)?-(x):(x))

int N;
int select[22];
int map[22][22];

int ans = 987654321;

int get(int idx, int stack) {
    if(idx == N+1) return -1;
    if(stack == N/2) {
        int A = 0, B = 0;
        for(int i=1;i<=N;i++) {
            if(select[i] == 1) {
                for(int j=1;j<=N;j++) {
                    if(j==i) continue;
                    if(select[j] == 1) A += map[i][j];
                }
            }
            else if(select[i] == 0) {
                for(int j=1;j<=N;j++) {
                    if(j==i) continue;
                    if(select[j] == 0) B += map[i][j];
                }
            }
        }
        if(ans > abs(A-B)) ans = abs(A-B);
        return 0;
    }
    for(int i=idx;i<=N;i++) {
         select[i] = 1;
         get(i+1, stack+1);
         select[i] = 0;
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for(int y=1;y<=N;y++) for(int x=1;x<=N;x++) scanf("%d", &map[y][x]);
    get(1,0);
    printf("%d", ans);
    return 0;
}