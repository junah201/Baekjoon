//1920  수 찾기

#include <stdio.h>
#include <algorithm>

using namespace std;

int N,M,r,l;
int A[100000],key;

int search(int key) {
    int low = 0;
    int high = N-1;
    int mid;

    while(low <= high) {
        mid = (low+high)/2;
        if(A[mid]==key) {
            return 1;
        } else if(key<A[mid]) {
            high = mid - 1;
        } else if(key>A[mid]) {
            low = mid + 1;
        }
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
        scanf("%d",&key);
        printf("%d\n",search(key));
    }
    return 0;
}