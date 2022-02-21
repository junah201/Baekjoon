//2231  분해합

#include <stdio.h>

int N;

int get(int x) {
    int sum=0;
    while (x>0) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        if(i+get(i)==N) {
            printf("%d",i);
            break;
        }
        if(i==N) {
            printf("0");
            break;
        }
    }
    return 0;
}