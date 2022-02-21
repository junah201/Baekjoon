//11720  숫자의 합

#include <stdio.h>

int N;
char input[101];
int sum=0;

int main() {
    scanf("%d",&N);
    scanf("%s",&input);
    for(int i=0;i<N;i++) {
        sum+=(int)input[i]-48;
    }
    printf("%d",sum);
    return 0;
}