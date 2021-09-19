//2440  별 찍기 - 3

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=0;i<N;i++){
        for(int j=i;j<N;j++) printf("*");
        printf("\n");
    }
    return 0;
}