//15727  조별과제를 하려는데 조장이 사라졌다

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
    if(N%5==0) printf("%d",N/5);
    else printf("%d",N/5+1);
    return 0;
}