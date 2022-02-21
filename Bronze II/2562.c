//2562  최댓값

#include <stdio.h>

int N,idx;
int max=0;

int main() {
    for(int i=0;i<9;i++) {
        scanf("%d ",&N);
        if(N>max) {
            max = N;
            idx = i+1;
        }
    }
    printf("%d\n%d",max,idx);
    return 0;
}