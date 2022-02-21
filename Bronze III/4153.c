//4153  직각삼각형

#include <stdio.h>

int main() {

	while (1) {
		long long int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0)
			break;

		if (x*x == y * y + z * z)
			printf("right\n");
		else if (y*y == x * x + z * z)
			printf("right\n");
		else if (z*z == x * x + y * y)
			printf("right\n");
		else
			printf("wrong\n");
	}
}