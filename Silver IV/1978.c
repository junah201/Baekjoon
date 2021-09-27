//1978  소수 찾기

#include <stdio.h>

int check(int x){
    if(x==1) return 0;
    int checker = 1;
    for(int i=2;i<x-1;i++) {
        if(x%i==0) {
            checker = 0;
            break;
        }
    }
    return checker;
}

int main() {
    int N; scanf("%d",&N);
    int count=0,num;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        count += check(num);
    }
    printf("%d",count);
    return 0;
}