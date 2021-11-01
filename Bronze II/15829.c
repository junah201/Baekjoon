//15829  Hashing

#include <stdio.h>

long long int div = 1234567891;

int main() {
	long long int temp,L,cnt=1,i,sum=0;
	char str[51];

	scanf("%lld", &L);
	scanf("%s", str);

	for (i = 0; i < L; i++) {
		temp = (str[i] - 96) * cnt;
		temp = temp % div;
		sum += temp;
		cnt *= 31;
        cnt = cnt % div;
		sum = sum % div;
	}
	printf("%d", sum);
}

/*
#include <stdio.h>

long long int a,N,R=31,M=1234567891;
long long int hashing=0;
char str[51];

long long int squared(long long int value, long long int cnt) {
    long long int result = 1;
    for(int i=0;i<cnt;i++) {
        result*=value;
    }
    return result;
}

int main() {
    scanf("%lld",&N);
    scanf("%s",str);
    for(int i=0;i<N;i++) {
        if(str[i]>=97 && str[i]<=122) {
            a=(int)str[i]-96;
        }
        hashing+=a*squared(R,i);
    }
    printf("%lld",hashing%M);
    return 0;
}
*/