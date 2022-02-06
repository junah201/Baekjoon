// 17610  양팔저울
// https://www.acmicpc.net/source/38656327

#include <stdio.h>

int N, map[15],sum,cnt;
int can[3000000];

int dfs(int idx, int result) {
    if(idx==N) {
        if(result>0) can[result] = 1;
        return 0;
    }
    dfs(idx+1, result);
    dfs(idx+1, result+map[idx]);
    dfs(idx+1, result-map[idx]);
    return 0;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d",&map[i]);
        sum += map[i];
    }
    dfs(0,0);
    for(int i=1;i<=sum;i++) cnt+=!can[i];
    printf("%d",cnt);
    return 0;
}