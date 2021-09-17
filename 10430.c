//	10430	나머지

#include <stdio.h>

int A,B,C;

int main() {
    scanf("%d %d %d",&A,&B,&C);
    printf("%d\n",(A+B)%C);
    printf("%d\n",((A%C)+(B%C))%C);
    printf("%d\n",(A*B)%C);
    printf("%d\n",((A%C)*(B%C))%C);

    return 0;
}