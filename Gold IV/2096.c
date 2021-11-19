//2096  내려가기

#include <stdio.h>

int N;
int a,b,c;
int temp0,temp2;
int maxDP[3],minDP[3];

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

int main() {
    scanf("%d",&N);
    scanf("%d %d %d",&maxDP[0],&maxDP[1],&maxDP[2]);
    minDP[0]=maxDP[0];
    minDP[1]=maxDP[1];
    minDP[2]=maxDP[2];
    for(int i=1;i<N;i++) {
        scanf("%d %d %d",&a,&b,&c);
        temp0=minDP[0];
        temp2=minDP[2];
        minDP[0]=min(minDP[0],minDP[1]) + a;
        minDP[2]=min(minDP[1],minDP[2]) + c;
        minDP[1]=min(min(temp0,minDP[1]),temp2) + b;
        temp0=maxDP[0];
        temp2=maxDP[2];
        maxDP[0]=max(maxDP[0],maxDP[1]) + a;
        maxDP[2]=max(maxDP[1],maxDP[2]) + c;
        maxDP[1]=max(max(temp0,maxDP[1]),temp2) + b;
    }
    printf("%d %d",max(max(maxDP[0],maxDP[1]),maxDP[2]),min(min(minDP[0],minDP[1]),minDP[2]));
    return 0;
}