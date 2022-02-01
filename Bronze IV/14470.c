// 14470  전자레인지
// https://www.acmicpc.net/source/38436691

#include <stdio.h>

int a, b, c, d, e;

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a < 0) printf("%d\n",-1 * a * c + d + e * b);
    else if (a > 0) printf("%d\n", e * (b-a));
    else printf("%d\n", d + e * b);
    return 0;
}
