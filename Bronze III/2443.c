//2443  별 찍기 - 6

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
	for(int i=0;i<N;i++){
        for(int j=0;j<i;j++) printf(" ");
        for(int j=i;j<N-1;j++) printf("*");
        printf("*");
        for(int j=i;j<N-1;j++) printf("*");
        printf(" ");
        printf("\n");
    }
    return 0;
}