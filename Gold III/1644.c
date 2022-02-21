//1644  소수의 연속합

#include <stdio.h>

int is_prime[4000000];
int primes[4000000];
int N,idx;

int tp() {
    int start=0;
    int end=0;
    int cnt=0;
    int sum=primes[0];
    while(start!=idx) {
        if(sum==N) {
            cnt++;
            sum+=primes[++end];
        }
        else if(sum<N) {
            end++;
            sum+=primes[end];
        }
        else if(sum>N) {
            sum-=primes[start++];
        }
        if(end>=idx) break;
        if(start>end) break;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for (int i = 2; i < 4000000; i++) {
        if(!is_prime[i]) {
            for(int j=i*2;j<4000000;j+=i) 
                is_prime[j] = 1;
        }
    }
    for (int i = 2; i < 4000000; i++) {
        if(!is_prime[i]) {
            primes[idx++] = i;
        }
    }
    /*
    for (int i=0;i<idx;i++) {
        printf("%d ",primes[i]);
    }*/
    printf("%d",tp());
    return 0;
}