//20053  최소, 최대 2

#include <stdio.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int T,N,A;
int min,max;

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        max=-1000000;
        min=1000000;
        for(int j=0;j<N;j++) {
            scanf("%d",&A);
            min=min(min,A);
            max=max(max,A);
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}