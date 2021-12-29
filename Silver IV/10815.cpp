//10815  숫자 카드

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int N,M,A[500000],B,len,low,high,mid;

int search(int x) {
    low = 0;
    high = N-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(A[mid]==x) return 1;
        else if(A[mid]>x) high = mid-1;
        else low = mid+1;
    }
    return 0;
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&A[i]);
    }
    sort(A,A+N);
    scanf("%d",&M);
    for(int i=0;i<M;i++) {
        scanf("%d",&B);
        printf("%d ", search(B));
    }
    return 0;
}

