#include <stdio.h>
#include <math.h>

int N;

int get(int num, char from, char by, char to) {
    if (num == 0) return 0;
    get(num - 1, from, to, by);
    printf("%c %c\n", from, to);
    get(num - 1, by, from, to);
    return 0;
}

int main() {
    scanf("%d", &N);
    printf("7\n");
    get(N, '1', '2', '3');
    return 0;
}