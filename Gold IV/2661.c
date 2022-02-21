// 2661  좋은 수열
// https://www.acmicpc.net/source/38656089

#include <stdio.h>

int N, K[100],is_print;

int same(int len, int a, int b) {
    for(int i=0;i<len;i++) {
        if(K[a-i] != K[b-i]) return 1;
    }
    return 0;
}

int check(int len) {
    for(int i=1;i<(len+1)/2;i++) {
        if(same(i, len-1, len-i-1)==0) return 0; 
    }
    return 1;
}

int bt(int idx) {
    if(is_print==1) return 0;
    if(idx == N+1) {
        for(int i=1;i<N+1;i++) printf("%d", K[i]);
        is_print = 1;
        return 1;
    }
    for(int i=1;i<=3;i++) {
        K[idx] = i;
        if(check(idx+1)==1) bt(idx+1);
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    bt(0);
    return 0;
// }

