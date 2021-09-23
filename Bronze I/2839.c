//2839  설탕 배달

#include <stdio.h>

int N;

int main() {
    scanf("%d",&N);
    if(N<9&&N%5!=0)
    if(N%5==0) printf("%d",N/5);
    else if((N%5)%3==0) printf("%d",N/5+(N%5)/3);
}