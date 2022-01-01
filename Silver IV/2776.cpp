//2776  암기왕

#include <stdio.h>
#include <algorithm>

int T,N,M,A[1000000],B[1000000];

int bs(int key) {
    int low = 0, high = N-1, mid;
    while(low<=high) {
        mid = (low+high)/2;
        if(A[mid]==key) return 1;
        else if(A[mid]>key) high = mid-1;
        else if(A[mid]<key) low = mid+1;
    }
    return 0;
}

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        for(int j=0;j<N;j++) scanf("%d",&A[j]);
        scanf("%d",&M);
        for(int j=0;j<M;j++) scanf("%d",&B[j]);
        std::sort(A,A+N);
        for(int j=0;j<M;j++) printf("%d\n",bs(B[j]));
    }
    return 0;
}