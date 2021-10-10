//17608  막대기

#include <stdio.h>

int N;
int input[100000]={0,};
int max=0;
int count=0;
int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    for(int i=N-1;i>=0;i--) {
        if(input[i]>max){
            count+=1;
            max=input[i];
        }
    }
    printf("%d",count);
    return 0;
}