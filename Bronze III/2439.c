//2439  별 찍기 - 2

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=1;i<=N;i++){
        for(int j=0;j<N-i;j++) printf(" ");
        for(int j=0;j<i;j++) printf("*");
        printf("\n");
    }
    return 0;
}