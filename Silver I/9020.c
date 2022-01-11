//9020  골드바흐의 추측

#include <stdio.h>

int is_prime[10000];
int T,N,idx,temp;

int find(int x) {
    int result;
    for(int i=2;i*2<=N;i++) {
        if(!is_prime[i] && !is_prime[x-i]) result=i;
    }
    return result;
}

int main() {
    for(int i=2;i<10000;i++) {
        if(!is_prime[i]) {
            for(int j=i*i;j<10000;j+=i) {
                is_prime[j]=1;
            }
        }
    }

    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        temp = find(N);
        printf("%d %d\n",temp,N-temp);
    }
    return 0;
}