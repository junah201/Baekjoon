//1009  분산처리

#include <stdio.h>
#include <math.h>

int N,A,B;

int main() {
    scanf("%d",&N);
	for(int i=0;i<N;i++) {
        scanf("%d %d",&A,&B);
        int result = A;
        for(int i=1;i<B;i++) result = (result*A)%10;
        result %= 10;
        if(result==0) printf("10\n");
        else printf("%d\n",result);
    }
    return 0;
}