//10952  A+B - 5

#include <stdio.h>

int A,B;

int main() {
    while (1) {
        scanf("%d %d", &A, &B);
        if(A==0 && B==0) break;
        printf("%d\n",A+B);
    }
    return 0;
}