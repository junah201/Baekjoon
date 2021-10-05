//2108  통계학

#include <stdio.h>
#include <algorithm>

using namespace std;

int N,sum=0;
int input[500000];
int check_int[500000]={0,};
int check_count[500000]={0,};

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    sort(input,input+N);
    for(int i=0;i<N;i++) sum += input[i];
    //평균
    printf("%d\n",sum/N);
    //중앙값
    if(N%2==1) printf("%d\n",input[N/2]);
    else printf("%d\n",(input[N/2]+input[N/2-1])/2);
    //최빈값
    check_int[0]=input[0];
    check_count[0]=1;
    for(int i=0;i<N;i++) {
        if()
    }
    //범위
    printf("%d\n",input[N-1]-input[0]);
}
