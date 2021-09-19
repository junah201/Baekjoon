//2442  별 찍기 - 5

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=0;i<N;i++){
        for(int j=i;j<N-1;j++) printf(" ");
        for(int j=0;j<i;j++) printf("*");
        printf("*");
        for(int j=0;j<i;j++) printf("*");
        printf(" ");
        printf("\n");
    }
    return 0;
}