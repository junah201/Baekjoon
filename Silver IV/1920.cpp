//1920  수 찾기

#include <stdio.h>
#include <algorithm>

using namespace std;
int check[100000],input[100000];
int N,M,num;
int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&check[i]);
    sort(check,check+N);
    scanf("%d",&M); 
    int start=0,end=N-1;
    for(int i=0;i<M;i++) {
        scanf("%d",&num);
        while(1) {
            if(!(start+1==end)) {
                printf("0\n");
                break;
            } else if(check[(start+end)/2]==num) {
                printf("1\n");
                break;
            } else if(check[(start+end)/2]>num) start=(start+end)/2;
            else if(check[(start+end)/2]<num) end=(start+end)/2;
        }
    }
    return 0;
}

