//14888  연산자 끼워넣기

#include <stdio.h>

int min=1000000000,max=-1000000000;
int N,A[100],cnt[4];

int get(int a,int b,int sign) {
    if(sign==0) return a+b;
    else if(sign==1) return a-b;
    else if(sign==2) return a*b;
    else return a/b;
}

void bt(int idx,int value) {
    if(idx==N-1) {
        if(value>max) max=value;
        if(value<min) min=value;
        return;
    }
    for(int i=0;i<4;i++) {
        if(cnt[i]) {
            cnt[i]--;
            bt(idx+1,get(value,A[idx+1],i));
            cnt[i]++;
        }
    }
    return;
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<4;i++) scanf("%d",&cnt[i]);
    bt(0,A[0]);
    printf("%d\n%d",max,min);
    return 0;
}