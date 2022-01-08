//1912  연속합

#include <stdio.h>

int N,sum[100000],max,temp;

int main() {
    scanf("%d",&N);
    scanf("%d",&sum[0]);
    max = sum[0];
    if(sum[0]<0) sum[0]=0;
    for(int i=1;i<N;i++) {
        scanf("%d",&temp);
        sum[i]=temp+sum[i-1];
        if(sum[i]>max) max=sum[i];
        if(sum[i]<0) sum[i]=0;
    }
    printf("%d",max);
    return 0;
}