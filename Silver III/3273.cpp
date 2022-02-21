//3273  두 수의 합

#include <stdio.h>
#include <algorithm>

int N,X,A[100000];

int tp() {
    int low=0,high=N-1,cnt=0;
    while(1) {
        if(low>=high) break;
        if(high==N) break;
        if(A[low]+A[high]==X) {
            cnt++;
            low++;
            high--;
        }
        else if(A[low]+A[high]<X)
            low++;
        else if(A[low]+A[high]>X)
            high--;
    }
    return cnt;
}

int main() {
    scanf("%d",&N);
    if(N==1) {
        printf("0");
        return 0;
    }
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    scanf("%d",&X);
    std::sort(A,A+N);
    printf("%d",tp());
    return 0;
}