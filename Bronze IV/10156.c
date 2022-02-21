// 10156 과자
// https://www.acmicpc.net/source/38400811

#include <stdio.h>

int K, N, M;

int main() {
	scanf("%d %d %d", &K, &N, &M);
	if (K * N > M) printf("%d", K * N - M);
	else printf("0");
    return 0;
} 