// 11054 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/source/39562009

#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int map[1000002], A[1000002], B[1000002];

int main() {
    int ans = 1;
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &map[i]);
        A[i] = 1;
        for(int j=1;j<N;j++) if(map[i] > map[j]) A[i] = max(A[i], A[j]+1);
    }
    for(int i=N;i>=0;i--) {
        B[i] = 1;
        for(int j=N;j>=0;j--) if(map[i] > map[j]) B[i] = max(B[i], B[j]+1);
    }
    for(int i=1;i<=N;i++) {
        ans = max(ans, A[i]+B[i]);
    }
    printf("%d",ans - 1);
    return 0;
}