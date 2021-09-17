//2588	곱셈

#include <stdio.h>

int A,B;

int main() {
    scanf("%d %d",&A,&B);

    printf("%d\n",A*(B%10)); //(3)
    printf("%d\n",A*((B%100)/10)); //(4)
    printf("%d\n",A*(B/100)); //(5)
    printf("%d\n",A*B); //(6)

    return 0;
}