//2908  상수

#include <stdio.h>

int A,B;

int get(int N) {
    int result = 0;
    while(N>0){
        result*=10;
        result += N%10;
        N/=10;
    }
    return result;
}

int main() {
    scanf("%d %d",&A,&B);
    if(get(A)>get(B)) printf("%d",get(A));
    else printf("%d",get(B));
    return 0;
}