//1330	두 수 비교하기

#include <stdio.h>

int A,B;

int main() {
    scanf("%d %d",&A,&B);

    if (A>B) {
        printf(">");
    }else if (A<B) {
        printf("<");
    }else {
        printf("==");
    }

    return 0;
}