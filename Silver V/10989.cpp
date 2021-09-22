//10989  수 정렬하기 3

#include <stdio.h>

int N,temp;
int input[10001] = {0,};

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf(" %d",&temp);
        input[temp]+=1;
    }
    for(int i=1;i<=10000;i++) {
        for(int j=0;j<input[i];j++) printf("%d\n",i);
    }
    return 0;
}