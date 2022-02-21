// 1292  쉽게 푸는 문제
// https://www.acmicpc.net/source/39392920

#include <stdio.h>

int sum[1000];
int idx = 1, temp = 1;
int A, B;

int main() {
    scanf("%d %d", &A, &B);
    while(idx <= B) {
        for(int i=0;i<temp;i++) {
           sum[idx] = temp + sum[idx - 1];
           idx++;
        }
        temp++;
    }
    printf("%d", sum[B]-sum[A-1]);
    return 0;
}