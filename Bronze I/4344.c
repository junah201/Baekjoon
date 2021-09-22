//4344  평균은 넘겠지

#include <stdio.h>

int C;
double N,count;
int input[2000] = {0,};
double sum,average;

int main() {
    scanf("%d",&C);
    for(int i=0;i<C;i++) {
        scanf(" %lf",&N);
        sum=0;
        for(int j=0;j<N;j++) {
            scanf("%d",&input[j]);
            sum += input[j];
        }
        average = sum/N;
        count = 0;
        for(int j=0;j<N;j++) {
            if(input[j]>average) count+=1;
        }
        printf("%.3lf%%\n",count/N*100.0);
    }
}