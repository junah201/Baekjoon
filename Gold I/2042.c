//2042  구간 합 구하기

#include <stdio.h>

int N, M, K;
int a,b,c;
int arr[1000000]={0,};
int sum[1000000]={0,};

int get_prefix_sum() {
    sum[0] = arr[0];
    for(int i=1;i<N;i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    return 0;
}

int main() {
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<N;i++) {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<M+K;i++) {
        scanf("%d %d %d",&a,&b,&c);
        if(a==1) {
            arr[b-1] = c;
        }else {
            get_prefix_sum();
            printf("%d\n",sum[c-1]-sum[b-2]);
        }
    }
    return 0;
}