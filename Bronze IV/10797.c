//10797  10부제

#include <stdio.h>

int N,count=0;
int input[5];

int main() {
    scanf("%d",&N);
    for(int i=0;i<5;i++) {
        scanf("%d",&input[i]);
        if(input[i]==N) count+=1;
    }
    printf("%d",count);
    return 0;
}