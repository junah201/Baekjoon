//2581  소수

#include <stdio.h>

int N,M;
int sum=0;
int min=10001;

int get(int x) {
    for(int i=2;i<x;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d",&N,&M);
    if(N==1) N=2;
    for(int i=N;i<=M;i++) {
        if(get(i)==1){
            sum+=i;
            if(min==10001) min = i;
        }
    }
    if(sum!=0) printf("%d %d",sum,min);
    else printf("-1");
    
    return 0;
}