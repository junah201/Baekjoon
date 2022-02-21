//2501  약수 구하기

#include <stdio.h>

int N,K,count=0;

int main() {
    scanf("%d %d",&N,&K);
    for(int i=1;i<=N;i++) {
        if(N%i==0) {
            count+=1;
            if(count==K) {
                printf("%d",i);
                break;
            }
        }
    }
    if(count<K) printf("0");
    return 0;
}