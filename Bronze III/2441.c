//2441  별 찍기 - 4

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=0;i<N;i++){
        for(int j=0;j<i;j++) printf(" ");
        for(int j=i;j<N;j++) printf("*");
        printf("\n");
    }
    return 0;
}