//16563  어려운 소인수분해

#include <stdio.h>
#include <vector>

using namespace std;

vector <int> primes;

int N,idx,K;
int not_prime[2500];


int main() {
    //아르키메데스의 체
    for(int i=2;i<2500;i++) {
        if(not_prime[i] == 0) {
            for(int j=i*i;j<2500;j+=i) {
                not_prime[j] = 1;
            }
        }
    }
    //소수 구분
    for(int i=2;i<2500;i++) {
        if(not_prime[i] == 0) {
            primes.push_back(i);
        }
    }
    //입력
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d", &K);
        for(int i=0;i<primes.size();i++) {
            while(K%primes[i]==0) {
                printf("%d ",primes[i]);
                K/=primes[i];
            }
        }
        if(K!=1) printf("%d",K);
        printf("\n");
    }
    return 0;
}