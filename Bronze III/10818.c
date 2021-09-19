//10818  최소, 최대

#include <stdio.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int N,A;
int min=1000000,max=-1000000;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf(" %d",&A);
        min = min(min,A);
        max = max(max,A);
    }
    printf("%d %d",min,max);
    return 0;
}