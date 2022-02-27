// 2410 2의 멱수의 합
// https://www.acmicpc.net/source/39711184

#include <bits/stdc++.h>
using namespace std;

int N;
int DP[1000002];

int main() {
    scanf("%d", &N);
    for (int cost = 1;cost <= N;cost *= 2) {
        DP[cost] += 1;
        for (int num = 1; num <= N;num++) {
            if (cost > num) continue;
            DP[num] += DP[num - cost];
            DP[num] %= 1000000000;
        }
        DP[cost] %= 1000000000;
    }
    printf("%d", DP[N] % 1000000000);
    return 0;
}