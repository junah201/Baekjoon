//8393  합

#include <stdio.h>

int N;
int sum = 0;

int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) sum+=i;
    printf("%d",sum);

    return 0;
}