//2438  별 찍기 - 1

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++) printf("*");
        printf("\n");
    }
    return 0;
}