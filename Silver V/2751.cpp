//2751  수 정렬하기 2

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int N; scanf("%d",&N);
    int Arr[1000000];
    for(int i=0;i<N;i++) scanf("%d",&Arr[i]);
    sort(Arr,Arr+N);
    for(int i=0;i<N;i++) printf("%d\n",Arr[i]);
    return 0;
} 