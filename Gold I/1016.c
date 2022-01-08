//1016  제곱 ㄴㄴ 수

#include <stdio.h>

int is_prime[1000000];
int primes[1000000];
int min,max,cnt;
int idx=0;

int check(int num) {
    for(int i=0;i<idx;i++) {
        if(num%(primes[i]*primes[i])==0) return 0;
        if(num<primes[i]*primes[i]) return 1;
    }
    return 1;
}

int main() {
    for(int i=2;i<1000000;i++) {
        is_prime[i]=1;
    }
    for(int i=2;i<1000000;i++) {
        if(is_prime[i]) {
            primes[idx++] = i;
            for(int j=i*2;j<1000000;j+=i) {
                is_prime[j]=0;
            }
        }
    }
    
    scanf("%d %d",&min,&max);
    for(int i=min;i<=max;i++) {
        cnt+=check(i);
    }
    printf("%d",cnt);
    return 0;
}