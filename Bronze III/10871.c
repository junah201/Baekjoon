//10871  X보다 작은 수

#include <stdio.h>

int N,X,A;

int main() {
    scanf("%d %d",&N,&X);
    for(int i=0;i<N;i++) {
        scanf("%d",&A);
        if(A<X) printf("%d ",A);
    }
    return 0;
}