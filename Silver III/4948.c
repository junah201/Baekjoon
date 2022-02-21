//4948 베르트랑 공준

#include <stdio.h>

int n,cnt;
int primes[300000];

int main() {
    for(int i=2;i<300000;i++){
        if(!primes[i]) {
            for(int j=i*2; j<300000; j+=i){
                primes[j] = 1;
            }
        }
    }
    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        cnt=0;
        for(int i=n+1;i<=2*n;i++) {
            cnt+=!primes[i];
        }
        printf("%d\n",cnt);
    }
    return 0;
}