//22693  N번째 큰 수

#include <stdio.h>
#include <algorithm>

using namespace std;

int T,A[10]; 

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        for(int j=0;j<10;j++) {
            scanf("%d",&A[j]);
        }
        sort(A,A+10);
        printf("%d\n",A[7]);
    }
    return 0;
}