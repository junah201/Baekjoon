//10816  숫자 카드 2

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int N,M,A[500000],B[500000],C[500000],key,len,low,high,mid;
int idx;

int search(int x) {
    low = 0;
    high = idx;
    while(low<=high) {
        mid = (low+high)/2;
        if(B[mid]==x) return C[mid];
        else if(B[mid]>x) high = mid-1;
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
    //개수 계산
    B[0] = A[0];
    C[0] = 1;
    idx=0;
    for(int i=1;i<N;i++) {
        if(A[i]==A[i-1]) C[idx]+=1;
        else {
            idx++;
            B[idx] = A[i];
            C[idx]++;
        }
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++) {
        scanf("%d",&key);
        printf("%d ", search(key));
    }
    return 0;
}