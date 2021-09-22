//1110  더하기 사이클

#include <stdio.h>

int N,x;
int result, count;
int get(int k) {
    int sum=0;
    while(k>0){
        sum+=k%10;
        k/=10;
    }
    return sum;
}


int main() {
    scanf("%d",&N);
    result = N;
    count = 0;
    while(1) {
        count+=1;
        x=result%10;
        result=get(result)%10+x*10;
        if(result==N) {
            printf("%d",count);
            break;
        }
    }
    return 0;
}