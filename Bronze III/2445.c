//2445  별 찍기 - 8

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<i+1;j++) printf("*");
        for(int j=i;j<N-1;j++) printf(" ");
        for(int j=i;j<N-1;j++) printf(" ");
        for(int j=0;j<i+1;j++) printf("*");
        printf(" ");
        printf("\n");
    }
	for(int i=1;i<N;i++){
        for(int j=i;j<N;j++) printf("*");
        for(int j=0;j<i;j++) printf(" ");
        for(int j=0;j<i;j++) printf(" ");
        for(int j=i;j<N;j++) printf("*");
        printf(" ");
        printf("\n");
    }
    return 0;
}