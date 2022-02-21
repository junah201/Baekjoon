//1838  버블 정렬

#include <stdio.h>

int A[500000],flag,temp,i,N;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for (i=0; i<N; i++) {
        flag = 0;
        for (int j=0; j<N-1; j++) {
            if (A[j] > A[j+1]) {
                flag = 1;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        if (flag == 0) {
            printf("%d",i);
            break;
        }
    }
    return 0;
}