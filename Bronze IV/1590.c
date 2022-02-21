// 1590 Identifying tea
// https://www.acmicpc.net/source/38196638

#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	int result = 0;
	for (int i=0;i<5;i++) {
		int guess;
		scanf("%d", &guess);
		if(T==guess) {
			result++;
		}
	}

	printf("%d", result);

	return 0;
}