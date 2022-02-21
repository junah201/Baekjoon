//2750  수 정렬하기

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int Arr[1000];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&Arr[i]);
    sort(Arr,Arr+N);
    for(int i=0;i<N;i++) printf("%d\n",Arr[i]);
    return 0;
}