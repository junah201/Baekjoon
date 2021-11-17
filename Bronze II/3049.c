//3049  다각형의 대각선

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",(n*(n-1)*(n-2)*(n-3))/24);
    return 0;
}