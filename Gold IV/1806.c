//1806  부분합

#include <stdio.h>

int N,S,A[100000];
int min,sum;

int tp() {
    int start = 0;
    int end = 0;
    int sum = A[0];
    while(end!=N) {
        if(sum<S) {
            end++;
            sum += A[end];
        } else {
            if(end+1-start<min) min = end+1-start;
            sum -= A[start];
            start++;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&S);
    if(S==0) {
        printf("1");
        return 0;
    }
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    min = N*2;
    tp();
    if(min==N*2) printf("0");
    else printf("%d",min);
    return 0;
}