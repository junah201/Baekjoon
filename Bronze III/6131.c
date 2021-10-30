//6131  완전 제곱수

#include <stdio.h>

int N;
int count = 0;

int main() {
    scanf("%d", &N);
    for(int i=1;i<=500;i++) {
        for(int j=1;j<i;j++) {
            if(i*i-j*j==N) {
                count+=1;
            }
        }
    }
    printf("%d", count);
    return 0;
}