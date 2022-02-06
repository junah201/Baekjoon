// 2668  숫자 고르기
// https://www.acmicpc.net/source/38656226

#include <stdio.h>

int N, K[110], check[110],result[110],is,cnt;

int dfs(int idx, int start) {
    if(idx == start && check[idx] == 1) {
        is = 1;
        result[idx] = 1;
        return 1;
    }
    if(check[idx] == 1) {
        is = 0;
        return -1;
    }
    check[idx] = 1;
    dfs(K[idx], start);
    if(is==0) check[idx]=0;
    return 0;
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d",&K[i]);
    for(int i=1;i<=N;i++) {
        if(check[i]==0) {
            is = 0;
            dfs(i, i);
            for(int i=1;i<=N;i++) if(check[i]) {
                result[i] = 1;
                check[i] = 0;
            }
        }
    }
    for(int i=1;i<=N;i++) if(result[i]==1) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=N;i++) if(result[i]==1) printf("%d\n", i);
    return 0;
}