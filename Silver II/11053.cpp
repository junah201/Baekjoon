// 11053 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/source/39561609

#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int map[1002], DP[1002];

int main() {
    int ans = 1;
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &map[i]);
        DP[i] = 1;
        for(int j=1;j<N;j++) if(map[i] > map[j]) DP[i] = max(DP[i], DP[j]+1);
        ans = max(ans, DP[i]);
    }
    printf("%d",ans);
    return 0;
}