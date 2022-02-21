//10974  모든 순열

#include <stdio.h>

int N;
int Arr[8];
int check[8] = {0,};

int get(int idx){
    if(idx==N) {
        for(int i=0;i<N;i++) printf("%d ",Arr[i]);
        printf("\n");
        return 0;
    }
    for(int i=1;i<=N;i++) {
        if(check[i-1]==0) {
            Arr[idx] = i;
            check[i-1] = 1;
            get(idx+1);
            check[i-1] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d",&N);
    get(0);
    return 0;
}